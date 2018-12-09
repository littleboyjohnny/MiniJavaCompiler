#pragma once

#include "Exp.h"
#include "Label.h"

namespace IRTree {

    class CNameExp : public IExp {
    public:
        explicit CNameExp(const CLabel _label) : label(_label) {

        }

        void Accept( IVisitor *visitor ) const {
            visitor->Visit( this );
        }

    private:
        const CLabel label;
    };

}