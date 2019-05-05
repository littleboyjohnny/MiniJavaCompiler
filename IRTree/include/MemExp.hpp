// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "Exp.h"
#include "./core/Visitor.h"
#include <memory>

namespace IRTree {

    class CMemExp : public IExp {
    public:
        explicit CMemExp( const IExp* _exp ) : exp( _exp ) {}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }


        std::unique_ptr<const IExp> exp;
    };

}