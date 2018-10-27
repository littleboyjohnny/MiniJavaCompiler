#include "IVisitor.h"

#ifndef COMPILERAST_IACCEPTABLE_H
#define COMPILERAST_IACCEPTABLE_H

class IAcceptable {
public:
    virtual void Accept( IVisitor* visitor ) = 0;
};

#endif //COMPILERAST_IACCEPTABLE_H
