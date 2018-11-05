#ifndef MINIJAVACOMPILER_EXPRESSIONPARAMLIST_HPP
#define MINIJAVACOMPILER_EXPRESSIONPARAMLIST_HPP

#include "../interfaces/IExpressionParamS.h"
#include "../interfaces/IExpression.h"
#include "../interfaces/IAdditionalExpressionParamS.h"
#include "../interfaces/IVisitor.h"

#include <vector>

class CExpressionParamList : public IExpressionParamS {
public:
    CExpressionParamList() {}

    void Accept( const IVisitor *visitor ) const {
        visitor->Visit(this);
    }

    mutable std::vector<const IExpression *> children;
};
#endif //MINIJAVACOMPILER_EXPRESSIONPARAMLIST_HPP
