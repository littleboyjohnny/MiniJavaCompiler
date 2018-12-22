#pragma once

#include "Exp.h"
#include "Stm.h"
#include "./core/Visitor.h"
#include <memory>

namespace IRTree {

    class CMoveStm : public IStm {
    public:
        explicit CMoveStm( const IExp* _dst, const IExp* _src ) : dst( _dst ), src( _src ) {}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }


        std::unique_ptr<const IExp> dst;
        std::unique_ptr<const IExp> src;
    };

}