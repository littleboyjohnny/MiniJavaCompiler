// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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

    private:
        std::unique_ptr<const IExp> dst;
        std::unique_ptr<const IExp> src;
    };

}