#pragma once

#include "Exp.h"
#include "Temp.h"

namespace IRTree {

    class CTempExp : public IExp {
    public:
        explicit CTempExp( const CTemp temp) {}

        void Accept( IVisitor* visitor ) const {
            visitor->Visit( this );
        }

    private:
        const CTemp temp;
    };

}