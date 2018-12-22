#pragma once

#include "SubtreeWrapper.hpp"
#include <cassert>

namespace IRTree {
    class CStmConverterer : public ISubtreeWrapper {
    public:
        explicit CStmConverterer( const IRTree::IStm* _stm ) : stm( _stm ) {}

        const IRTree::IExp* ToExp() const override {
            assert(false);
        }

        const IRTree::IStm* ToStm() const override {
            return stm;
        }

        const IRTree::IStm* ToConditional( const IRTree::CLabel* t, const IRTree::CLabel* f ) const override {
            //TODO:
            return nullptr;
        }


        const IRTree::IStm* stm;
    };
}