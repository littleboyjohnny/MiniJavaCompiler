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

