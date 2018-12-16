#pragma once

#include "ConditionalWrapper.hpp"
#include "CJumpStm.hpp"

namespace IRTree {
    class CRelativeCmpWrapper : public CConditionalWrapper {
    public:
        CRelativeCmpWrapper( const CCJumpStm::ERelOp _op, const IRTree::IExp* _e1, const IRTree::IExp* _e2) :
            op( _op ), e1( _e1 ), e2( _e2 ) {}
        virtual const IRTree::IStm* ToConditional( const IRTree::CLabel* t, const IRTree::CLabel* f ) const {
            return new CCJumpStm(op, e1, e2, t, f);
        }

    private:
        const CCJumpStm::ERelOp op;
        const IExp* e1;
        const IExp* e2;
    };
}