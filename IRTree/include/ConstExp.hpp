#pragma once

#include "Exp.h"
#include "./core/Visitor.h"

namespace IRTree {

    class CConstExp : public IExp {
    public:
        explicit CConstExp( int _value ) : value( _value ) {}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }

    private:
        const int value;
    };

}