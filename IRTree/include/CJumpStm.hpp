#pragma once

#include "Exp.h"
#include "Stm.h"
#include "./core/Visitor.h"
#include <memory>
#include "include/Label.h"

namespace IRTree {

    class CCJumpStm : public IStm {
    public:
        enum class ERelOp
        {
            LT
        };

        explicit CCJumpStm( const ERelOp _relOp,
                const IExp* _left,
                const IExp* _right ,
                const CLabel _ifTrue,
                const CLabel _ifFalse )
                : relOp( _relOp ), left( _left ),
                right( _right ), ifTrue( _ifTrue ), ifFalse( _ifFalse ) {}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }

    private:
        const ERelOp relOp;
        std::unique_ptr<const IExp> left;
        std::unique_ptr<const IExp> right;
        const CLabel ifTrue;
        const CLabel ifFalse;

    };

}