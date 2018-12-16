#pragma once

#include "Exp.h"
#include "Stm.h"
#include "./core/Visitor.h"
#include <memory>

namespace IRTree {

    class CEseqExp : public IExp {
    public:
        explicit CEseqExp( const IStm* _stm, const IExp* _exp ) : stm(_stm), exp( _exp ) {}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }

    private:
        std::unique_ptr<const IStm> stm;
        std::unique_ptr<const IExp> exp;
    };

}