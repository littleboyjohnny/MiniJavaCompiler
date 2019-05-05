#pragma once

#include "SubtreeWrapper.hpp"
#include "Temp.h"
#include "TempExp.hpp"
#include "ConstExp.hpp"
#include "Label.h"
#include "LabelStm.hpp"
#include "MoveStm.hpp"
#include "SeqStm.hpp"
#include "EseqExp.hpp"

namespace IRTree {
    class CConditionalWrapper : public ISubtreeWrapper {
    public:
        virtual const IRTree::IExp* ToExp() const {
            CTemp* r = new CTemp("ToExp");
            CLabel* t = new CLabel("TrueLabelToExp");
            CLabel* f = new CLabel("FalseLabelToExp");
            return new CEseqExp(
                    new CSeqStm(
                            new CMoveStm(
                                    new CTempExp(r),
                                    new CConstExp(1)
                            ),
                            new CSeqStm(
                                    ToConditional(t, f),
                                    new CSeqStm(
                                            new CLabelStm(*f),
                                            new CSeqStm(
                                                    new CMoveStm(
                                                            new CTempExp(r),
                                                            new CConstExp(0)
                                                    ),
                                                    new CLabelStm(*t)
                                            )
                                    )
                            )
                    ),
                    new CTempExp(r)
            );
        }
        virtual const IRTree::IStm* ToStm() const {}
        virtual const IRTree::IStm* ToConditional( const IRTree::CLabel* t, const IRTree::CLabel* f ) const = 0;
    };
}