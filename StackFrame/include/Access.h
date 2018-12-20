#pragma once

#include "include/Exp.h"
#include "include/Temp.h"

class IAccess {
public:
    virtual ~IAccess() = default;
    virtual const IRTree::IExp* GetExp() const = 0;
};