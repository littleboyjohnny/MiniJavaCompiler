// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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

    private:
        std::vector<std::unique_ptr<const IStm>> statements;
    };

}