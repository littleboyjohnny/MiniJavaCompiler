#pragma once

#include "Exp.h"
#include "Stm.h"
#include "Temp.h"
#include "Label.h"

namespace IRTree {
    class ISubtreeWrapper {
    public:
        virtual ~ISubtreeWrapper() {}
        virtual const IRTree::IExp* ToExp() const = 0;
        virtual const IRTree::IStm* ToStm() const = 0;
        virtual const IRTree::IStm* ToConditional( const IRTree::CLabel* t, const IRTree::CLabel* f ) const = 0;
    };
}