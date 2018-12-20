// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "SubtreeWrapper.hpp"
#include <cassert>

namespace IRTree {
    class CStmConverterer : public ISubtreeWrapper {
    public:
        CStmConverterer( const IRTree::IStm* _stm ) : stm( _stm ) {}

        const IRTree::IExp* ToExp() {
            assert(false);
        }

        const IRTree::IStm* ToStm() {
            return stm;
        }

        const IRTree::IStm* ToConditional( const IRTree::CLabel* t, const IRTree::CLabel* f ) {
            //TODO:
        }

    private:
        const IRTree::IStm* stm;
    };
}