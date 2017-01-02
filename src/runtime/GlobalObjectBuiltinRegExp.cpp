#include "Escargot.h"
#include "GlobalObject.h"
#include "Context.h"
#include "RegExpObject.h"
#include "ArrayObject.h"

namespace Escargot {

static Value builtinRegExpConstructor(ExecutionState& state, Value thisValue, size_t argc, Value* argv, bool isNewExpression)
{
    bool patternIsRegExp = argv[0].isObject() && argv[0].asObject()->isRegExpObject();
    if (patternIsRegExp) {
        if (argv[1].isUndefined())
            return argv[0];
#ifndef USE_ES6_FEATURE
        else
            ErrorObject::throwBuiltinError(state, ErrorObject::TypeError, "Cannot supply flags when constructing one RegExp from another");
#endif
    }
    RegExpObject* regexp;
    if (isNewExpression && thisValue.isObject() && thisValue.asObject()->isRegExpObject()) {
        regexp = thisValue.asPointerValue()->asObject()->asRegExpObject();
    } else {
        regexp = new RegExpObject(state);
    }
    // TODO(ES6): consider the case that patternIsRegExp is true
    const StaticStrings* strings = &state.context()->staticStrings();
    String* patternStr = (argv[0].isUndefined()) ? strings->defaultRegExpString.string() : argv[0].toString(state);
    if (patternStr->length() == 0)
        patternStr = strings->defaultRegExpString.string();

    String* optionStr = (argv[1].isUndefined()) ? String::emptyString : argv[1].toString(state);
    regexp->setSource(state, patternStr);
    regexp->setOption(state, optionStr);
    return regexp;
}

static Value builtinRegExpExec(ExecutionState& state, Value thisValue, size_t argc, Value* argv, bool isNewExpression)
{
    RESOLVE_THIS_BINDING_TO_OBJECT(thisObject, RegExp, test);
    if (!thisObject->isRegExpObject()) {
        ErrorObject::throwBuiltinError(state, ErrorObject::TypeError, state.context()->staticStrings().RegExp.string(), true, state.context()->staticStrings().exec.string(), errorMessage_GlobalObject_ThisNotRegExpObject);
    }
    RegExpObject* regexp = thisObject->asRegExpObject();
    String* str = argv[0].toString(state);
    double lastIndex = regexp->computedLastIndex(state);
    if (lastIndex < 0 || lastIndex > str->length()) {
        regexp->setLastIndex(Value(0));
        return Value(Value::Null);
    }
    RegexMatchResult result;
    if (regexp->matchNonGlobally(state, str, result, false, lastIndex)) {
        // TODO(ES6): consider Sticky and Unicode
        if (regexp->option() & RegExpObject::Option::Global)
            regexp->setLastIndex(Value(result.m_matchResults[0][0].m_end));
        return regexp->createRegExpMatchedArray(state, result, str);
    }

    regexp->setLastIndex(Value(0));
    return Value(Value::Null);
}

static Value builtinRegExpTest(ExecutionState& state, Value thisValue, size_t argc, Value* argv, bool isNewExpression)
{
    RESOLVE_THIS_BINDING_TO_OBJECT(thisObject, RegExp, test);
    if (!thisObject->isRegExpObject()) {
        ErrorObject::throwBuiltinError(state, ErrorObject::TypeError, state.context()->staticStrings().RegExp.string(), true, state.context()->staticStrings().test.string(), errorMessage_GlobalObject_ThisNotRegExpObject);
    }
    RegExpObject* regexp = thisObject->asRegExpObject();
    String* str = argv[0].toString(state);
    double lastIndex = regexp->computedLastIndex(state);
    if (lastIndex < 0 || lastIndex > str->length()) {
        regexp->setLastIndex(Value(0));
        return Value(false);
    }
    RegexMatchResult result;
    bool testResult = regexp->match(state, str, result, true, lastIndex);
    return Value(testResult);
}

static Value builtinRegExpToString(ExecutionState& state, Value thisValue, size_t argc, Value* argv, bool isNewExpression)
{
    RESOLVE_THIS_BINDING_TO_OBJECT(thisObject, RegExp, toString);

    if (!thisObject->isRegExpObject()) {
        ErrorObject::throwBuiltinError(state, ErrorObject::TypeError, state.context()->staticStrings().RegExp.string(), true, state.context()->staticStrings().toString.string(), errorMessage_GlobalObject_ThisNotRegExpObject);
    }
    RegExpObject* regexp = thisObject->asRegExpObject();

    StringBuilder builder;
    builder.appendString("/");
    builder.appendString(regexp->get(state, ObjectPropertyName(state.context()->staticStrings().source)).value(state, thisObject).toString(state));
    builder.appendString("/");

    RegExpObject::Option option = regexp->option();

    char flags[5] = { 0 };
    int flags_idx = 0;
    if (option & RegExpObject::Option::Global) {
        flags[flags_idx++] = 'g';
    }
    if (option & RegExpObject::Option::IgnoreCase) {
        flags[flags_idx++] = 'i';
    }
    if (option & RegExpObject::Option::MultiLine) {
        flags[flags_idx++] = 'm';
    }
    if (option & RegExpObject::Option::Sticky) {
        flags[flags_idx++] = 'y';
    }
    builder.appendString(flags);
    return builder.finalize();
}

void GlobalObject::installRegExp(ExecutionState& state)
{
    m_regexp = new FunctionObject(state, NativeFunctionInfo(state.context()->staticStrings().RegExp, builtinRegExpConstructor, 2, [](ExecutionState& state, size_t argc, Value* argv) -> Object* {
                                      return new RegExpObject(state, String::emptyString, String::emptyString);
                                  }),
                                  FunctionObject::__ForBuiltin__);
    m_regexp->markThisObjectDontNeedStructureTransitionTable(state);
    m_regexp->setPrototype(state, m_functionPrototype);

    m_regexpPrototype = m_objectPrototype;
    m_regexpPrototype = new RegExpObject(state);
    m_regexpPrototype->setPrototype(state, m_objectPrototype);

    m_regexpPrototype->defineOwnProperty(state, ObjectPropertyName(state.context()->staticStrings().constructor), ObjectPropertyDescriptor(m_regexp, (ObjectPropertyDescriptor::PresentAttribute)(ObjectPropertyDescriptor::WritablePresent | ObjectPropertyDescriptor::ConfigurablePresent)));

    m_regexp->setFunctionPrototype(state, m_regexpPrototype);

    const StaticStrings* strings = &state.context()->staticStrings();
    // $21.2.5.2 RegExp.prototype.exec
    m_regexpPrototype->defineOwnPropertyThrowsException(state, ObjectPropertyName(strings->exec),
                                                        ObjectPropertyDescriptor(new FunctionObject(state, NativeFunctionInfo(strings->exec, builtinRegExpExec, 1, nullptr, NativeFunctionInfo::Strict)), (ObjectPropertyDescriptor::PresentAttribute)(ObjectPropertyDescriptor::WritablePresent | ObjectPropertyDescriptor::ConfigurablePresent)));
    // $21.2.5.13 RegExp.prototype.test
    m_regexpPrototype->defineOwnPropertyThrowsException(state, ObjectPropertyName(strings->test),
                                                        ObjectPropertyDescriptor(new FunctionObject(state, NativeFunctionInfo(strings->test, builtinRegExpTest, 1, nullptr, NativeFunctionInfo::Strict)), (ObjectPropertyDescriptor::PresentAttribute)(ObjectPropertyDescriptor::WritablePresent | ObjectPropertyDescriptor::ConfigurablePresent)));

    // $21.2.5.14 RegExp.prototype.toString
    m_regexpPrototype->defineOwnPropertyThrowsException(state, ObjectPropertyName(strings->toString),
                                                        ObjectPropertyDescriptor(new FunctionObject(state, NativeFunctionInfo(strings->toString, builtinRegExpToString, 1, nullptr, NativeFunctionInfo::Strict)), (ObjectPropertyDescriptor::PresentAttribute)(ObjectPropertyDescriptor::WritablePresent | ObjectPropertyDescriptor::ConfigurablePresent)));
    // $B.2.5.1 RegExp.prototype.compile

    defineOwnProperty(state, ObjectPropertyName(state.context()->staticStrings().RegExp),
                      ObjectPropertyDescriptor(m_regexp, (ObjectPropertyDescriptor::PresentAttribute)(ObjectPropertyDescriptor::WritablePresent | ObjectPropertyDescriptor::ConfigurablePresent)));
}
}
