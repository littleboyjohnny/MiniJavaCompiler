// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "CSymbolTableVisualizer.h"

#include "include/SymbolTable.h"

#include <iostream>
#include <fstream>
#include <cassert>


CSymbolTableVisualizer::CSymbolTableVisualizer() :
    out( std::cout )
{
    //
}

CSymbolTableVisualizer::CSymbolTableVisualizer( std::ostream &_out ) :
    out( _out )
{
    //
}

void CSymbolTableVisualizer::Visuzlize( CSymbolTable* table )
{
    assert( table != nullptr );

    CBlockScope* block = table->PopBlockScope();

    out << "::Global::" << std::endl;
    visuzlizeSingleBlock( block, 0 );

    table->PushBlockScope( block );
}

void CSymbolTableVisualizer::visuzlizeSingleBlock( const CBlockScope* block, int depth )
{
    assert( block != nullptr );
    assert( depth >= 0 );

    visualizeVariables( block, depth );
    visualizeClasses( block, depth );
    visualizeMethods( block, depth );
}

void CSymbolTableVisualizer::visualizeMethods( const CBlockScope *block, int depth )
{
    auto names = block->GetMethodNames();
    if( !names.empty() ) {
        printSpaces( depth );
        out << "::Methods::" << std::endl;
        for( const CSymbol* name : names ) {
            const CMethodInfo* methodInfo = block->TryResolveMethod( name );
            printSpaces( depth );
            out << methodInfo->GetStringRepresentation() << std::endl;
            visualizeVariables( methodInfo->GetScope(), depth + 1 );
        }
        out << std::endl;
    }
}

void CSymbolTableVisualizer::visualizeVariables( const CBlockScope *block, int depth )
{
    auto names = block->GetVariableNames();
    if( !names.empty() ) {
        printSpaces( depth );
        out << "::Variables::" << std::endl;
        for( const CSymbol* name : names ) {
            const CVariableInfo* variableInfo = block->TryResolveVariable( name );
            printSpaces( depth );
            out << variableInfo->GetStringRepresentation() << std::endl;
        }
        out << std::endl;
    }
}

void CSymbolTableVisualizer::visualizeClasses( const CBlockScope *block, int depth )
{
    auto names = block->GetClassNames();
    if( !names.empty() ) {
        printSpaces( depth );
        out << "::Classes::" << std::endl;
        for( const CSymbol* name : names ) {
            const CClassInfo* classInfo = block->TryResolveClass( name );
            printSpaces( depth );
            out << classInfo->GetStringRepresentation() << std::endl;
            visualizeVariables( classInfo->GetScope(), depth + 1 );
            visualizeMethods( classInfo->GetScope(), depth + 1 );
        }
        out << std::endl;
    }
}

void CSymbolTableVisualizer::printSpaces( int depth )
{
    for( int i = 0; i < depth; ++i ) {
        out << "  ";
    }
}


