#ifndef MINIJAVACOMPILER_STATEMENTLIST_HPP
#define MINIJAVACOMPILER_STATEMENTLIST_HPP

#include "../interfaces/IStatement.h"
#include "../interfaces/IStatementS.h"
#include "../core/IVisitor.h"

#include <vector>

class CStatementList : public IStatementS {
public:
    CStatementList() {}

    void Accept(const IVisitor *visitor) const {
        visitor->Visit(this);
    }

    mutable std::vector<const IStatement *> children;
};

#endif //MINIJAVACOMPILER_STATEMENTLIST_HPP
