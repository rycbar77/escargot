/*
 * Copyright (c) 2019-present Samsung Electronics Co., Ltd
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 *  USA
 */

#include "Escargot.h"
#include "Object.h"
#include "runtime/Context.h"
#include "runtime/SmallValue.h"
#include "runtime/FunctionObject.h"
#include "BoundFunctionObject.h"

namespace Escargot {

BoundFunctionObject::BoundFunctionObject(ExecutionState& state, Value& targetFunction, Value& boundThis, size_t boundArgc, Value* boundArgv, const Value& length, const Value& name)
#ifndef ESCARGOT_ENABLE_ES2015
    : Object(state, ESCARGOT_OBJECT_BUILTIN_PROPERTY_NUMBER + 4, false)
#else
    : Object(state, ESCARGOT_OBJECT_BUILTIN_PROPERTY_NUMBER + 2, false)
#endif
    , m_boundTargetFunction(targetFunction)
    , m_boundThis(boundThis)
{
    ASSERT(targetFunction.isObject() == true);
    m_structure = state.context()->defaultStructureForBoundFunctionObject();
    m_values[ESCARGOT_OBJECT_BUILTIN_PROPERTY_NUMBER + 0] = length;
    m_values[ESCARGOT_OBJECT_BUILTIN_PROPERTY_NUMBER + 1] = name;

#ifndef ESCARGOT_ENABLE_ES2015
    // Call the [[DefineOwnProperty]] internal method of F with arguments "caller", PropertyDescriptor {[[Get]]: thrower, [[Set]]: thrower, [[Enumerable]]: false, [[Configurable]]: false}, and false.
    // Call the [[DefineOwnProperty]] internal method of F with arguments "arguments", PropertyDescriptor {[[Get]]: thrower, [[Set]]: thrower, [[Enumerable]]: false, [[Configurable]]: false}, and false.
    auto data = state.context()->globalObject()->throwerGetterSetterData();
    m_values[ESCARGOT_OBJECT_BUILTIN_PROPERTY_NUMBER + 2] = Value(data);
    m_values[ESCARGOT_OBJECT_BUILTIN_PROPERTY_NUMBER + 3] = Value(data);
#endif
    Value proto = targetFunction.asObject()->getPrototype(state);
    Object::setPrototype(state, proto);

    if (boundArgc > 0) {
        m_boundArguments.resizeWithUninitializedValues(boundArgc);
        for (size_t i = 0; i < boundArgc; i++) {
            m_boundArguments[i] = boundArgv[i];
        }
    }
}

// https://www.ecma-international.org/ecma-262/6.0/#sec-bound-function-exotic-objects-call-thisargument-argumentslist
Value BoundFunctionObject::call(ExecutionState& state, const Value& thisValue, const size_t calledArgc, Value* calledArgv)
{
    // Let args be a new list containing the same values as the list boundArgs in the same order followed by the same values as the list argumentsList in the same order.
    size_t boundArgc = m_boundArguments.size();
    size_t mergedArgc = boundArgc + calledArgc;
    Value* mergedArgv = ALLOCA(mergedArgc * sizeof(Value), Value, state);
    for (size_t i = 0; i < boundArgc; i++) {
        mergedArgv[i] = m_boundArguments[i];
    }
    if (calledArgc > 0) {
        memcpy(mergedArgv + boundArgc, calledArgv, sizeof(Value) * calledArgc);
    }

    // Return Call(target, boundThis, args).
    return Object::call(state, m_boundTargetFunction, m_boundThis, mergedArgc, mergedArgv);
}

// https://www.ecma-international.org/ecma-262/6.0/#sec-bound-function-exotic-objects-construct-argumentslist-newtarget
Object* BoundFunctionObject::construct(ExecutionState& state, const size_t calledArgc, Value* calledArgv, const Value& newTarget)
{
    ASSERT(isConstructor() == true);
    // Let args be a new list containing the same values as the list boundArgs in the same order followed by the same values as the list argumentsList in the same order.
    size_t boundArgc = m_boundArguments.size();
    size_t mergedArgc = boundArgc + calledArgc;
    Value* mergedArgv = ALLOCA(mergedArgc * sizeof(Value), Value, state);
    for (size_t i = 0; i < boundArgc; i++) {
        mergedArgv[i] = m_boundArguments[i];
    }
    if (calledArgc > 0) {
        memcpy(mergedArgv + boundArgc, calledArgv, sizeof(Value) * calledArgc);
    }

    // If SameValue(F, newTarget) is true, let newTarget be target.
    Value newConstructTarget = (Value(this) == Value(newTarget)) ? Value(m_boundTargetFunction) : newTarget;

    // Return Construct(target, args, newTarget).
    return Object::construct(state, m_boundTargetFunction, mergedArgc, mergedArgv, newConstructTarget);
}
}