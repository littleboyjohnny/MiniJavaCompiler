#pragma once

#include "Stm.h"
#include <memory>
#include <vector>

namespace IRTree {
    class CStmList
    {
    public:
        CStmList() = default;

        explicit CStmList( const IStm* expression )
        {
            Add( expression );
        }

        void Add( const IStm* expression )
        {
            statements.emplace_back( expression );
        }


        std::vector<std::unique_ptr<const IStm>> statements;
    };

}