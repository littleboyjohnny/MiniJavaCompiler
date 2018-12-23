// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "Exp.h"
#include "Stm.h"
#include "./core/Visitor.h"
#include <memory>
#include "Label.h"

namespace IRTree {

    class CJumpStm : public IStm {
    public:
        explicit CJumpStm( const CLabel _target ) : target( _target ){}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }


        const CLabel target;
    };
}
