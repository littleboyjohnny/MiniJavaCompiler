// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

#include "../interfaces/IExpression.h"
#include "../interfaces/IStatement.h"
#include "../core/IVisitor.h"

class CPrintlnStatement : public IStatement {
public:
    CPrintlnStatement( const IExpression * const _expression ) :
        expression( _expression )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IExpression > expression;
};


