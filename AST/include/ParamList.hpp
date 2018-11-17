#pragma once

#include "../interfaces/IParams.h"
#include "../core/IVisitor.h"
#include "../interfaces/IParam.h"
#include "../interfaces/IAdditionalParamS.h"

#include <vector>

class CParamList : public IParams {
public:
    CParamList() {}

    void Accept( IVisitor *visitor ) const {
        visitor->Visit(this);
    }

    mutable std::vector<const IParam *> children;
};


