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


CSymbol* CSymbol::GetIntern( const std::string& src )
{
    static std::unordered_map<std::string, std::unique_ptr<CSymbol>> allStrings;
    auto cached = allStrings.find( src );
    if( cached != allStrings.end() ) {
        return cached->second.get();
    }
    CSymbol* newVal = new CSymbol( src );
    allStrings.insert( { src, std::unique_ptr<CSymbol>( newVal ) } );
    return newVal;
}