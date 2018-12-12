#pragma once

#include "Exp.h"
#include "Stm.h"
#include "./core/Visitor.h"
#include <memory>
#include "Label.h"

namespace IRTree {

    class CJumpStm : public IStm {
    public:
        explicit CJumpStm( const IExp* _exp, const CLabel _target ) : exp( _exp ), target( _target ){}

        void Accept( IVisitor *visitor ) const {
            visitor->Visit( this );
        }

    private:
        std::unique_ptr<const IExp> exp;
        const CLabel target;
    };
}
