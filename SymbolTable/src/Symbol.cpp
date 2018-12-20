// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "include/Symbol.h"

#include <string>
#include <memory>


CSymbol::CSymbol( const std::string& _str ) :
        str(_str)
{}


const std::string& CSymbol::GetString() const
{
    return str;
}


const CSymbol* CSymbol::GetIntern( const std::string& src )
{
    static std::unordered_map<std::string, std::unique_ptr<const CSymbol>> allStrings;
    auto cached = allStrings.find( src );
    if( cached != allStrings.end() ) {
        return cached->second.get();
    }
    CSymbol* newVal = new CSymbol( src );
    allStrings.insert( { src, std::unique_ptr<CSymbol>( newVal ) } );
    return newVal;
}