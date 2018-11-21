#pragma once

#include "../core/IAcceptable.h"
#include <string>

class IType : public IAcceptable {
public:
    virtual std::string GetString() const = 0;
};
