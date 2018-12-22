#pragma once

#include "Exp.h"
#include "Stm.h"
#include "./core/Visitor.h"
#include <memory>

namespace IRTree {

    class CExpStm : public IStm {
    public:
        explicit CExpStm( const IExp* _exp) : exp( _exp ) {}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }


        std::unique_ptr<const IExp> exp;
    };

}