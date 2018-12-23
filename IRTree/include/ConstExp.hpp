// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "Exp.h"
#include "./core/Visitor.h"

namespace IRTree {

    class CConstExp : public IExp {
    public:
        explicit CConstExp( int _value ) : value( _value ) {}

        void Accept( IVisitorIRT *visitor ) const override {
            visitor->Visit( this );
        }


        const int value;
    };

}