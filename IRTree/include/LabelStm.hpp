// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "Stm.h"
#include "./core/Visitor.h"
#include <memory>
#include "Label.h"

namespace IRTree {

    class CLabelStm : public IStm {
    public:
        explicit CLabelStm( const CLabel _label ) : label( _label ) {}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }


        const CLabel label;
    };

}