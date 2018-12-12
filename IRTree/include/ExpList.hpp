#pragma once

#include "Exp.h"
#include <memory>
#include <vector>

namespace IRTree {
    class CExpList
    {
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

    private:
        std::vector<std::unique_ptr<const IExp>> expressions;
    };

}