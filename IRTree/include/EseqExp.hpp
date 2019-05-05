// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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


        std::unique_ptr<const IStm> stm;
        std::unique_ptr<const IExp> exp;
    };

}