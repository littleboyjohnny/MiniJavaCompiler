#pragma once

#include "../IRTPredefines.h"

namespace IRTree {
    class IVisitorIRT {
    public:
        virtual void Visit(const CConstExp* acceptable) = 0;
        virtual void Visit(const CNameExp* acceptable) = 0;
        virtual void Visit(const CTempExp* acceptable) = 0;
        virtual void Visit(const CBinOpExp* acceptable) = 0;
        virtual void Visit(const CMemExp* acceptable) = 0;
        virtual void Visit(const CCallExp* acceptable) = 0;
        virtual void Visit(const CEseqExp* acceptable) = 0;

        virtual void Visit(const CMoveStm* acceptable) = 0;
        virtual void Visit(const CExpStm* acceptable) = 0;
        virtual void Visit(const CJumpStm* acceptable) = 0;
        virtual void Visit(const CCJumpStm* acceptable) = 0;
        virtual void Visit(const CSeqStm* acceptable) = 0;
        virtual void Visit(const CLabelStm* acceptable) = 0;

        virtual void Visit(const CLabel* acceptable) = 0;
        virtual void Visit(const CExpList* acceptable) = 0;

    };
}