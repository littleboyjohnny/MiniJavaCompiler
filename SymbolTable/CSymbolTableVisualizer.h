#pragma once

#include <include/Table.h>

class CSymbolTableVisualizer {
public:
    CSymbolTableVisualizer();
    explicit CSymbolTableVisualizer( std::ostream& _out );

    void Visuzlize( CTable* table );

private:
    std::ostream& out;

    void visuzlizeSingleBlock( const CBlockScope* block, int depth );
    void visualizeMethods( const CBlockScope* block, int depth );
    void visualizeVariables( const CBlockScope* block, int depth );
    void visualizeClasses( const CBlockScope* block, int depth );

    void printSpaces( int depth );
};
