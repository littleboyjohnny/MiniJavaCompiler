#include "parser.tab.hpp"
#include <cstdio>
#include <cassert>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include "TokenMap.hpp"

class Builder {
public:
    Builder(const char * filename) {
        forlex = this;
        index = 0;
        std::ifstream fin(filename);
        std::string token;
        while(fin >> token) {
            if ( token == "IDENTIFIER" ) {
                std::string val;
                fin >> val;
                identifierVals.push_back( val );
            } else if ( token == "INTLITERAL" ) {
                int val;
                fin >> val;
                intliteralVals.push_back( val );
            }
            tokens.push_back(tokenMap->tokenToId[token]);
        }
        fin.close();
    }

    ~Builder() {
        forlex = nullptr;
    }

    int getNextTokenId() {
        if (index < tokens.size()) {
            return tokens[index++];
        }
        return 0;
    }

    std::string getNextIdentifierVal() {
        assert(identifierVals.size() != 0);
        std::string val = identifierVals.front();
        identifierVals.pop_front();
        return val;
    }

    int getNextIntliteralVal() {
        assert( intliteralVals.size() != 0 );
        int val = intliteralVals.front();
        intliteralVals.pop_front();
        return val;
    }

    static Builder* forlex;
    static TokenMap* tokenMap;
private:
    int index;
    std::vector<int> tokens;
    std::list<std::string> identifierVals;
    std::list<int> intliteralVals;
};

Builder* Builder::forlex = nullptr;
TokenMap* Builder::tokenMap = new TokenMap();

int yylex() {
    int tokenID = Builder::forlex->getNextTokenId();
    if ( tokenID == Builder::tokenMap->tokenToId[ "IDENTIFIER" ] ) {
        std::string val = Builder::forlex->getNextIdentifierVal();
        yylval.terminalIdentifier = new CTerminalIdentifier( val.c_str(), val.size() );
    } else if ( tokenID == Builder::tokenMap->tokenToId[ "INTLITERAL" ] ) {
        yylval.terminalIntliteral = new CTerminalIntliteral( Builder::forlex->getNextIntliteralVal() );
    }
    return tokenID;
}
