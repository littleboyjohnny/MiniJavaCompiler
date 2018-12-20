// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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


