#pragma once

#include "Exp.h"
#include "Temp.h"

namespace IRTree {

    class CTempExp : public IExp {
    public:
        explicit CTempExp( const CTemp* _temp) : temp( *_temp ) {}

        void Accept( IVisitorIRT* visitor ) const {
            visitor->Visit( this );
        }

    private:
        const CTemp temp;
    };

}