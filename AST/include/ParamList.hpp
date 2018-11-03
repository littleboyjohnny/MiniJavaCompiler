#ifndef MINIJAVACOMPILER_PARAMLIST_HPP
#define MINIJAVACOMPILER_PARAMLIST_HPP

#include "../interfaces/IParams.h"
#include "../interfaces/IVisitor.h"
#include "../interfaces/IParam.h"
#include "../interfaces/IAdditionalParamS.h"

#include <vector>

class CParamList : public IParams {
public:
    CParamList() {}

    void Accept(const IVisitor *visitor) const {
        visitor->Visit(this);
    }

    mutable std::vector<const IParam *> children;
};

#endif //MINIJAVACOMPILER_PARAMLIST_HPP
