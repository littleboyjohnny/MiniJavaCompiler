// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

#include "../interfaces/IMethodDeclaration.h"
#include "../core/IVisitor.h"
#include "../interfaces/IType.h"
#include "../interfaces/IParams.h"
#include "../interfaces/IVarDeclarationS.h"
#include "../interfaces/IStatementS.h"
#include "../interfaces/IExpression.h"

#include "../core/TerminalIdentifier.hpp"

class CMethodDeclaration : public IMethodDeclaration {
public:
    CMethodDeclaration( const IType * const _returnType,
            const CTerminalIdentifier * const _methodIdentifier,
            const IParams * const _params,
            const IVarDeclarationS * const _varDeclarationS,
            const IStatementS * const _statementS,
            const IExpression * const _returnExpression ) :
        returnType( _returnType ),
        methodIdentifier( _methodIdentifier ),
        params( _params ),
        varDeclarationS( _varDeclarationS ),
        statementS( _statementS ),
        returnExpression( _returnExpression )
    {}

    void Accept( IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IType> returnType;
    const std::unique_ptr<const CTerminalIdentifier> methodIdentifier;
    const std::unique_ptr<const IParams> params;
    const std::unique_ptr<const IVarDeclarationS> varDeclarationS;
    const std::unique_ptr<const IStatementS> statementS;
    const std::unique_ptr<const IExpression> returnExpression;
};


