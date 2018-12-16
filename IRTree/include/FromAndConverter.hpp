#pragma once

#include "ConditionalWrapper.hpp"

namespace IRTree {
    class CFromAndConverter : public CConditionalWrapper {
    public:
        CFromAndConverter( const IRTree::IExp* _leftArg, const IRTree::IExp* _rightArg )
            : leftArg( _leftArg ), rightArg( _rightArg ) {}

        virtual const IRTree::IStm* ToConditional( const IRTree::CLabel* t, const IRTree::CLabel* f ) {

        }

    private:
        const IRTree::IExp* leftArg;
        const IRTree::IExp* rightArg;
    };
}