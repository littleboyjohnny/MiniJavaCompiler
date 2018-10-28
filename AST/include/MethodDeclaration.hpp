#ifndef MINIJAVACOMPILER_METHODDECLARATION_HPP
#define MINIJAVACOMPILER_METHODDECLARATION_HPP

#include "../interfaces/IMethodDeclaration.h"
#include "../interfaces/IVisitor.h"
#include "../interfaces/IType.h"
#include "../interfaces/IParams.h"
#include "../interfaces/IVarDeclarationS.h"
#include "../interfaces/IStatementS.h"
#include "../interfaces/IExpression.h"

#include "../include/TerminalIdentifier.hpp"

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

    void Accept( IVisitor * visitor )
    {
        visitor->Visit( this );
    }

private:
    const IType * const returnType;
    const CTerminalIdentifier * const methodIdentifier;
    const IParams * const params;
    const IVarDeclarationS * const varDeclarationS;
    const IStatementS * const statementS;
    const IExpression * const returnExpression;
};

#endif //MINIJAVACOMPILER_METHODDECLARATION_HPP
