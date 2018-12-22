#pragma once

#include "Stm.h"
#include "./core/Visitor.h"
#include <memory>

namespace IRTree {

    class CSeqStm : public IStm {
    public:
        explicit CSeqStm( const IStm* _left, const IStm* _right ) : left( _left ), right( _right ) {}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }


        std::unique_ptr<const IStm> left;
        std::unique_ptr<const IStm> right;
    };

}