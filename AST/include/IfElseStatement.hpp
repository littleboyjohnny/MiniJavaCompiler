// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

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

    const std::unique_ptr<const IExpression> condition;
    const std::unique_ptr<const IStatement> ifStatement;
    const std::unique_ptr<const IStatement> elseStatement;
};


