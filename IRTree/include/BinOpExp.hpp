#pragma once

#include "Exp.h"
#include "./core/Visitor.h"
#include <memory>

namespace IRTree {

    class CBinOpExp : public IExp {
    public:
        enum class EBinOp
        {
            AND,
            PLUS,
            MINUS,
            MULTIPLY
        };

        explicit CBinOpExp( const EBinOp _binOp,
                const IExp* _left,
                const IExp* _right ) : binOp( _binOp ), left( _left ), right( _right ) {}

        void Accept( IVisitor *visitor ) const {
            visitor->Visit( this );
        }

    private:
        const EBinOp binOp;
        std::unique_ptr<const IExp> left;
        std::unique_ptr<const IExp> right;

    };

}