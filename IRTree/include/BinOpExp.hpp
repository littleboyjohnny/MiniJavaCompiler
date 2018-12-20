// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "Exp.h"
#include "core/Visitor.h"
#include "include/BinaryOpExpression.hpp"

#include <memory>


namespace IRTree {

    class CBinOpExp : public IExp {
    public:
        using EBinOp = CBinaryOpExpression::OpType;
        /*
        enum class EBinOp
        {
            AND,
            PLUS,
            MINUS,
            MULTIPLY
        };
         */

        explicit CBinOpExp( const EBinOp _binOp,
                const IExp* _left,
                const IExp* _right ) : binOp( _binOp ), left( _left ), right( _right ) {}

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }

    private:
        const EBinOp binOp;
        std::unique_ptr<const IExp> left;
        std::unique_ptr<const IExp> right;

    };

}