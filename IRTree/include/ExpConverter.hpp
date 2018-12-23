// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "SubtreeWrapper.hpp"
#include "Label.h"
#include "ExpStm.hpp"
#include "Temp.h"
#include "CJumpStm.hpp"
#include "ConstExp.hpp"

namespace IRTree {
    class CExpConverter : public ISubtreeWrapper {
    public:
        CExpConverter( const IRTree::IExp* e ) : expr( e ) {}

        const IRTree::IExp* ToExp() const { return expr; }

        const IRTree::IStm* ToStm() const {
            return new IRTree::CExpStm( expr );
        }

        const IRTree::IStm* ToConditional( const IRTree::CLabel* t, const IRTree::CLabel* f ) const {
            return new CCJumpStm(
                        CCJumpStm::ERelOp::LT,
                        new IRTree::CConstExp(0),
                        expr,
                        *t,
                        *f
            );
        }


        const IRTree::IExp* expr;
    };
}