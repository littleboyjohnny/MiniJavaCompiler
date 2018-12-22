#pragma once

#include "Exp.h"
#include "Label.h"
#include "core/Visitor.h"

namespace IRTree {

    class CNameExp : public IExp {
    public:
        explicit CNameExp(const CLabel _label) : label(_label) {}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }


        const CLabel label;
    };

}