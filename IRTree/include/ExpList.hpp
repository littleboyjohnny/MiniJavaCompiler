#pragma once

#include "Exp.h"
#include <memory>
#include <vector>

#include "./core/Acceptable.h"

namespace IRTree {
    class CExpList : public IAcceptable {
    public:
        CExpList() = default;

        explicit CExpList( const IExp* expression )
        {
            Add( expression );
        }

        void Add( const IExp* expression )
        {
            expressions.emplace_back( expression );
        }

        void Accept( IVisitorIRT *visitor ) const {
            visitor->Visit( this );
        }


        std::vector<std::unique_ptr<const IExp>> expressions;
    };

}