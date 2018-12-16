#pragma once

namespace IRTree {

    class IVisitorIRT;

    class IAcceptable {
    public:
        virtual void Accept( IVisitorIRT *visitor ) const = 0;
    };

}