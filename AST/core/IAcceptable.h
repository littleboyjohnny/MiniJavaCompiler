#ifndef COMPILERAST_IACCEPTABLE_H
#define COMPILERAST_IACCEPTABLE_H

class IVisitor;

class IAcceptable {
public:
    virtual void Accept( const IVisitor* visitor ) const = 0;
};

#endif //COMPILERAST_IACCEPTABLE_H
