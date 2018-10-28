#ifndef COMPILERAST_IVISITOR_H
#define COMPILERAST_IVISITOR_H

class IAcceptable;

class IVisitor {
public:
    virtual void Visit( IAcceptable* acceptable ) = 0; //// TODO: добавить перегрузку для каждого нетерминала
};

#endif //COMPILERAST_IVISITOR_H
