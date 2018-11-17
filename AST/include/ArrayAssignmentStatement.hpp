#pragma once

#include "../interfaces/IStatement.h"
#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"
#include "../core/TerminalIdentifier.hpp"

class CArrayAssignmentStatement : public IStatement {
public:
    CArrayAssignmentStatement( const CTerminalIdentifier * const _arrayName,
                               const IExpression * const _indexExpression,
                               const IExpression * const _expression ) :
        arrayName( _arrayName ),
        indexExpression( _indexExpression ),
        expression( _expression )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const CTerminalIdentifier * const arrayName;
    const IExpression * const indexExpression;
    const IExpression * const expression;
};


