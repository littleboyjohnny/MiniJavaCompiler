#include "include/Symbol.h"

#include <string>


CSymbol::CSymbol( const std::string& _str ) :
        str(_str)
{}


const std::string& CSymbol::String() const
{
    return str;
}


CSymbol* CSymbol::getIntern( const std::string& src )
{
    static std::unordered_map<std::string, CSymbol*> allStrings;
    auto cached = allStrings.find( src );
    if( cached != allStrings.end() ) {
        return cached->second;
    }
    CSymbol* newVal = new CSymbol( src );
    allStrings.insert( { src, newVal } );
    return newVal;
}