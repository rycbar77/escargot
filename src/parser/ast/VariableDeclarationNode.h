/*
 * Copyright (c) 2016-present Samsung Electronics Co., Ltd
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

#ifndef VariableDeclarationNode_h
#define VariableDeclarationNode_h

#include "DeclarationNode.h"
#include "VariableDeclaratorNode.h"

namespace Escargot {

class VariableDeclarationNode : public DeclarationNode {
public:
    friend class ScriptParser;
    explicit VariableDeclarationNode(VariableDeclaratorVector&& decl)
        : DeclarationNode()
    {
        m_declarations = decl;
    }

    virtual ~VariableDeclarationNode()
    {
    }

    virtual ASTNodeType type() { return ASTNodeType::VariableDeclaration; }
    VariableDeclaratorVector& declarations() { return m_declarations; }
    virtual void generateStatementByteCode(ByteCodeBlock* codeBlock, ByteCodeGenerateContext* context)
    {
        size_t len = m_declarations.size();
        for (size_t i = 0; i < len; i++) {
            m_declarations[i]->generateStatementByteCode(codeBlock, context);
        }
    }

    virtual void generateStoreByteCode(ByteCodeBlock* codeBlock, ByteCodeGenerateContext* context, ByteCodeRegisterIndex src, bool needToReferenceSelf)
    {
        ASSERT(m_declarations.size() == 1);
        if (m_declarations[0]->init()) {
            src = m_declarations[0]->init()->getRegister(codeBlock, context);
            m_declarations[0]->init()->generateExpressionByteCode(codeBlock, context, src);
            context->giveUpRegister();
        }
        m_declarations[0]->id()->generateStoreByteCode(codeBlock, context, src, false);
    }

    virtual void generateResolveAddressByteCode(ByteCodeBlock* codeBlock, ByteCodeGenerateContext* context)
    {
    }

    virtual void generateReferenceResolvedAddressByteCode(ByteCodeBlock* codeBlock, ByteCodeGenerateContext* context)
    {
        generateExpressionByteCode(codeBlock, context, context->getRegister());
    }

    virtual void generateExpressionByteCode(ByteCodeBlock* codeBlock, ByteCodeGenerateContext* context, ByteCodeRegisterIndex dstRegister)
    {
        size_t len = m_declarations.size();
        for (size_t i = 0; i < len; i++) {
            m_declarations[i]->generateStatementByteCode(codeBlock, context);
        }
    }

protected:
    VariableDeclaratorVector m_declarations; // declarations: [ VariableDeclarator ];
    // kind: "var" | "let" | "const";
};
}

#endif
