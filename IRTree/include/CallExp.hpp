// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "Exp.h"
#include "./core/Visitor.h"
#include <memory>
#include "ExpList.hpp"

namespace IRTree {

    class CCallExp : public IExp {
    public:
        explicit CCallExp( const IExp* _exp, const CExpList* _args ) : exp( _exp ), args(_args) {}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }

    private:
        std::unique_ptr<const IExp> exp;
        std::unique_ptr<const CExpList> args;

    };

}