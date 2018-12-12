#pragma once

#include "Exp.h"
#include "./core/Visitor.h"
#include <memory>

namespace IRTree {

    class CMemExp : public IExp {
    public:
        explicit CMemExp( const IExp* _exp ) : exp( _exp ) {}

        void Accept( IVisitor *visitor ) const {
            visitor->Visit( this );
        }

    private:
        std::unique_ptr<const IExp> exp;
    };

}