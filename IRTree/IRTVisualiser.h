#pragma once

#include <cstdio>

#include "IRTPredefines.h"
#include "./core/Visitor.h"
#include "core/CodeFragment.hpp"

namespace IRTree {
    class CIRTVisualiser : public IVisitorIRT {
    public:
        CIRTVisualiser( const char* );
        ~CIRTVisualiser();

        void Visit(const CConstExp* acceptable);
        void Visit(const CNameExp* acceptable);
        void Visit(const CTempExp* acceptable);
        void Visit(const CBinOpExp* acceptable);
        void Visit(const CMemExp* acceptable);
        void Visit(const CCallExp* acceptable);
        void Visit(const CEseqExp* acceptable);

        void Visit(const CMoveStm* acceptable);
        void Visit(const CExpStm* acceptable);
        void Visit(const CJumpStm* acceptable);
        void Visit(const CCJumpStm* acceptable);
        void Visit(const CSeqStm* acceptable);
        void Visit(const CLabelStm* acceptable);

        void Visit(const CLabel* acceptable);
        void Visit(const CExpList* acceptable);
        
        void printIRT( const CCodeFragment* head );
    private:
        FILE* file;

        void printEdge( const void * from, const void * to );
        void addLabel( const void * pMemory, const char * label );
    };
}