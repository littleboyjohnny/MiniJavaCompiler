// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "ConditionalWrapper.hpp"
#include "include/CJumpStm.hpp"
#include "include/LabelStm.hpp"
#include "include/SeqStm.hpp"

namespace IRTree {
    class CFromAndConverter : public CConditionalWrapper {

    public:
        CFromAndConverter( const IRTree::ISubtreeWrapper* _leftArg, const IRTree::ISubtreeWrapper* _rightArg )
            : leftArg( _leftArg ), rightArg( _rightArg ) {

            static int counter = 0;
            index = counter++;
        }

        const IRTree::IStm* ToConditional( const IRTree::CLabel* t, const IRTree::CLabel* f ) const override {
            CLabel loc( std::string("___FromAndNext_") + (char)('0' + index) );
            return new CSeqStm(
                        leftArg->ToConditional( &loc, f ),
                        new CSeqStm(
                                    new CLabelStm( loc ),
                                    rightArg->ToConditional( t, f )
                                )
                    );
        }


        const IRTree::ISubtreeWrapper* leftArg;
        const IRTree::ISubtreeWrapper* rightArg;
        int index;
    };
}