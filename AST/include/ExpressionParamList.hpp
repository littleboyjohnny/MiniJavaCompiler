// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "../interfaces/IExpressionParamS.h"
#include "../interfaces/IExpression.h"
#include "../interfaces/IAdditionalExpressionParamS.h"
#include "../core/IVisitor.h"

#include <vector>

class CExpressionParamList : public IExpressionParamS {
public:
    CExpressionParamList() {}

    void Accept( IVisitor *visitor ) const {
        visitor->Visit(this);
    }

    mutable std::vector<const IExpression *> children;
};

