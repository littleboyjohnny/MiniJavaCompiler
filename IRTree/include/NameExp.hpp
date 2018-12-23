// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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