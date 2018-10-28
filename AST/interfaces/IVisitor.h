#ifndef COMPILERAST_IVISITOR_H
#define COMPILERAST_IVISITOR_H

class IVisitor {
public:
    virtual void Visit() = 0; //// TODO: добавить перегрузку для каждого нетерминала
};

#endif //COMPILERAST_IVISITOR_H
