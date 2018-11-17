#pragma once

#include "../interfaces/IStatement.h"
#include "../interfaces/IStatementS.h"
#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"


class CIfElseStatement : public IStatement {
public:
    CIfElseStatement( const IExpression * const _condition,
                      const IStatement * const _ifStatement,
                      const IStatement * const _elseStatement ) :
        condition( _condition ),
        ifStatement( _ifStatement ),
        elseStatement( _elseStatement )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IExpression * const condition;
    const IStatement * const ifStatement;
    const IStatement * const elseStatement;
};


