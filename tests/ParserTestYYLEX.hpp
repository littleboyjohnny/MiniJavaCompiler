#include "parser.tab.hpp"
#include <cstdio>
#include <vector>
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
        while(std::getline(fin, token)) {
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

    static Builder* forlex;
private:
    static TokenMap* tokenMap;
    int index;
    std::vector<int> tokens;
};

Builder* Builder::forlex = nullptr;
TokenMap* Builder::tokenMap = new TokenMap();

int yylex() {
    return Builder::forlex->getNextTokenId();
}
