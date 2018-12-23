// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CFalseExpression : public IExpression
{
public:
    CFalseExpression(){}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};


