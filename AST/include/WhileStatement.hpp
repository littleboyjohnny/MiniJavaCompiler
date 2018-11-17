#pragma once

#include <memory>

#include "../interfaces/IStatement.h"
#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CWhileStatement : public IStatement {
public:
    CWhileStatement( const IExpression * const _condition, const IStatement * const _statement ) :
        condition( _condition ),
        statement( _statement )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IExpression> condition;
    const std::unique_ptr<const IStatement> statement;
};


