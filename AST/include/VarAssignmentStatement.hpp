#pragma once

#include "../interfaces/IStatement.h"
#include "../interfaces/IExpression.h"
#include "../core/TerminalIdentifier.hpp"

class CVarAssignmentStatement : public IStatement {
public:
    CVarAssignmentStatement( const CTerminalIdentifier * const _varName,
                             const IExpression * const _expression ) :
        varName( _varName ),
        expression( _expression )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const CTerminalIdentifier * const varName;
    const IExpression * const expression;
};


