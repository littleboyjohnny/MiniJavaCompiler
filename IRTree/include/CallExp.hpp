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


        std::unique_ptr<const IExp> exp;
        std::unique_ptr<const CExpList> args;

    };

}