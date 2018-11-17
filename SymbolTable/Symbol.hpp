#pragma once
#include <string>
#include <unordered_map>

class CSymbol {
public:
    const std::string& String() const;

    CSymbol( const std::string& str): String(str);

    CSymbol( const CSymbol& ) = delete;
    void operator=( const CSymbol& ) = delete;

    CSymbol* getIntern( const std::string& src )
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
};