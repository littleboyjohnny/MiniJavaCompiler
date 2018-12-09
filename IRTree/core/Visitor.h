#pragma once

#include "../IRTPredefines.h"

namespace IRTree {
    class IVisitor {
    public:
        virtual void Visit(const CConstExp* acceptable) = 0;
        virtual void Visit(const CNameExp* acceptable) = 0;
        virtual void Visit(const CTempExp* acceptable) = 0;
    };
}