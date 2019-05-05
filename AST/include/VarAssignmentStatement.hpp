// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

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

    const std::unique_ptr<const CTerminalIdentifier> varName;
    const std::unique_ptr<const IExpression> expression;
};


