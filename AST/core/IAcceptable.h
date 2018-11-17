#pragma once

class IVisitor;

class IAcceptable {
public:
    virtual void Accept( const IVisitor* visitor ) const = 0;
};


