#pragma once

namespace IRTree {

    class IVisitor;

    class IAcceptable {
    public:
        virtual void Accept( IVisitor *visitor ) const = 0;
    };

}