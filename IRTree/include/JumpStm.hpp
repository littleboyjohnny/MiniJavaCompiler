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

    private:
        const CLabel target;
    };
}
