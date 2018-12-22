#pragma once

#include <string>

#include "core/Acceptable.h"
#include "core/Visitor.h"

namespace IRTree {

    class CLabel : public IAcceptable {
    public:
        explicit CLabel( const std::string s ) : label(s) {}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }


        const std::string label;
    };

}