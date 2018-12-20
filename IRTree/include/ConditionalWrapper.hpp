// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "SubtreeWrapper.hpp"

namespace IRTree {
    class CConditionalWrapper : public ISubtreeWrapper {
    public:
        virtual const IRTree::IExp* ToExp() const {}
        virtual const IRTree::IStm* ToStm() const {}
        virtual const IRTree::IStm* ToConditional( const IRTree::CLabel* t, const IRTree::CLabel* f ) const = 0;
    };
}