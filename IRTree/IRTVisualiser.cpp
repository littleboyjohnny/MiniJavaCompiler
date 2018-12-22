#include "IRTVisualiser.h"
#include "IRTIncludes.h"


IRTree::CIRTVisualiser::CIRTVisualiser(const char* filename) {
    file = fopen( filename, "w" );
    fprintf( file, "digraph AST {\n" );
}

IRTree::CIRTVisualiser::~CIRTVisualiser() {
    fprintf( file, "}" );
    fclose( file );
}

void IRTree::CIRTVisualiser::printIRT( const CCodeFragment* head ) {
    const CCodeFragment* iter = head;
    while( iter ) {
        iter->Body->Accept( this );
        iter = iter->Next;
    }
}

void IRTree::CIRTVisualiser::addLabel( const void * pMemory, const char * label ) {
    fprintf( file, "\t%lld [label=\"%s\"];\n", (const long long)pMemory, label );
}

void IRTree::CIRTVisualiser::printEdge( const void * from, const void * to ) {
    fprintf( file, "\t%lld -> %lld;\n", (const long long)from, (const long long)to );
}

void IRTree::CIRTVisualiser::Visit(const CConstExp* acceptable) {
    addLabel( acceptable, "ConstExp" );
}

void IRTree::CIRTVisualiser::Visit(const CNameExp* acceptable) {
    printEdge( acceptable, &acceptable->label );
    acceptable->label.Accept( this );

    addLabel(acceptable, "NameExp" );
}

void IRTree::CIRTVisualiser::Visit(const CTempExp* acceptable) {
    if ( acceptable->temp ) {
        printEdge( acceptable, acceptable->temp );
        addLabel( acceptable->temp, acceptable->temp->label.c_str() );
    }

    addLabel(acceptable, "TempExp" );
}

void IRTree::CIRTVisualiser::Visit(const CBinOpExp* acceptable) {
    auto resolveOp = []( CBinOpExp::EBinOp type ) -> char {
        switch (type) {
            case CBinOpExp::EBinOp::PLUS : return '+';
            case CBinOpExp::EBinOp::MULTIPLY: return '*';
            case CBinOpExp::EBinOp::LESS : return '<';
            case CBinOpExp::EBinOp::AND : return '&';
            case CBinOpExp::EBinOp::MINUS : return '-';
            case CBinOpExp::EBinOp::XOR : return 'X';
        }
    };

    char* t = new char[4];
    printEdge( acceptable, t );
    char op =  resolveOp( acceptable->binOp );
    addLabel( t, &op );
    //delete[] t;

    if ( acceptable->left ) {
        printEdge( acceptable, acceptable->left.get() );
        acceptable->left->Accept( this );
    }

    if ( acceptable->right ) {
        printEdge( acceptable, acceptable->right.get() );
        acceptable->right->Accept( this );
    }

    addLabel(acceptable, "BinOpExp" );
}

void IRTree::CIRTVisualiser::Visit(const CMemExp* acceptable) {
    if ( acceptable->exp ) {
        printEdge( acceptable, acceptable->exp.get() );
        acceptable->exp->Accept( this );
    }

    addLabel(acceptable, "MemExp" );
}

void IRTree::CIRTVisualiser::Visit(const CCallExp* acceptable) {
    if ( acceptable->exp ) {
        printEdge( acceptable, acceptable->exp.get() );
        acceptable->exp->Accept( this );
    }

    if ( acceptable->args ) {
        printEdge( acceptable, acceptable->args.get() );
        acceptable->args->Accept( this );
    }

    addLabel(acceptable, "CallExp" );
}

void IRTree::CIRTVisualiser::Visit(const CEseqExp* acceptable) {
    if ( acceptable->stm ) {
        printEdge( acceptable, acceptable->stm.get() );
        acceptable->stm->Accept( this );
    }

    if ( acceptable->exp ) {
        printEdge( acceptable, acceptable->exp.get() );
        acceptable->exp->Accept( this );
    }

    addLabel(acceptable, "EseqExp" );
}

void IRTree::CIRTVisualiser::Visit(const CMoveStm* acceptable) {
    if ( acceptable->dst ) {
        printEdge( acceptable, acceptable->dst.get() );
        acceptable->dst->Accept( this );
    }

    if ( acceptable->src ) {
        printEdge( acceptable, acceptable->src.get() );
        acceptable->src->Accept( this );
    }

    addLabel(acceptable, "MoveStm" );
}

void IRTree::CIRTVisualiser::Visit(const CExpStm* acceptable) {
    if ( acceptable->exp ) {
        printEdge( acceptable, acceptable->exp.get() );
        acceptable->exp->Accept( this );
    }

    addLabel(acceptable, "ExpStm" );
}

void IRTree::CIRTVisualiser::Visit(const CJumpStm* acceptable) {
    const CLabel* ptr = &acceptable->target;
    printEdge( acceptable, ptr );
    ptr->Accept( this );

    addLabel(acceptable, "JumpStm" );
}

void IRTree::CIRTVisualiser::Visit(const CCJumpStm* acceptable) {
    char* t = new char('<');
    printEdge( acceptable, t );
    addLabel(t, t);
    //delete t;

    if ( acceptable->left ) {
        printEdge( acceptable, acceptable->left.get() );
        acceptable->left->Accept( this );
    }

    if ( acceptable->right ) {
        printEdge( acceptable, acceptable->right.get() );
        acceptable->right->Accept( this );
    }

    printEdge( acceptable, &acceptable->ifTrue );
    acceptable->ifTrue.Accept( this );

    printEdge( acceptable, &acceptable->ifFalse );
    acceptable->ifFalse.Accept( this );

    addLabel(acceptable, "CJumpStm" );
}

void IRTree::CIRTVisualiser::Visit(const CSeqStm* acceptable) {
    if ( acceptable->left ) {
        printEdge( acceptable, acceptable->left.get() );
        acceptable->left->Accept( this );
    }

    if ( acceptable->right ) {
        printEdge( acceptable, acceptable->right.get() );
        acceptable->right->Accept( this );
    }

    addLabel(acceptable, "SeqStm" );
}

void IRTree::CIRTVisualiser::Visit(const CLabelStm* acceptable) {
    const CLabel* ptr = &acceptable->label;

    printEdge( acceptable, ptr );
    ptr->Accept( this );

    addLabel(acceptable, "LabelStm" );
}

void IRTree::CIRTVisualiser::Visit(const CLabel* acceptable) {
    std::string s = "Label::" + acceptable->label;
    addLabel(acceptable, s.c_str() );
}

void IRTree::CIRTVisualiser::Visit(const CExpList* acceptable) {
    for (int i = 0; i < acceptable->expressions.size(); i++) {
        printEdge( acceptable, acceptable->expressions[i].get() );
        acceptable->expressions[i]->Accept( this );
    }

    addLabel(acceptable, "ExpList" );
}