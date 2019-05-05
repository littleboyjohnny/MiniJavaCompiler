// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "../interfaces/IStatement.h"
#include "../interfaces/IStatementS.h"
#include "../core/IVisitor.h"

#include <vector>

class CStatementList : public IStatementS {
public:
    CStatementList() {}

    void Accept( IVisitor *visitor ) const {
        visitor->Visit( this );
    }

    mutable std::vector<const IStatement*> children;
};


