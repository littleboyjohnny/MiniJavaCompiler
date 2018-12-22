#pragma once

#include "ConditionalWrapper.hpp"
#include "include/CJumpStm.hpp"

namespace IRTree {
    class CFromAndConverter : public CConditionalWrapper {
    public:
        CFromAndConverter( const IRTree::IExp* _leftArg, const IRTree::IExp* _rightArg )
            : leftArg( _leftArg ), rightArg( _rightArg ) {}

        const IRTree::IStm* ToConditional( const IRTree::CLabel* t, const IRTree::CLabel* f ) const override {
            return new IRTree::CCJumpStm(CCJumpStm::ERelOp::LT, leftArg, rightArg, t, f);
        }

    private:
        const IRTree::IExp* leftArg;
        const IRTree::IExp* rightArg;
    };
}