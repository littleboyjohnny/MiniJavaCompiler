// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <map>
#include <string>

class TokenMap {
public:
    TokenMap() {
        tokenToId["IDENTIFIER"] = 258;
        tokenToId["INTLITERAL"] = 259;
        tokenToId["IF"] = 260;
        tokenToId["ELSE"] = 261;
        tokenToId["WHILE"] = 262;
        tokenToId["_TRUE"] = 263;
        tokenToId["_FALSE"] = 264;
        tokenToId["PUBLIC"] = 265;
        tokenToId["STATIC"] = 266;
        tokenToId["EXTENDS"] = 267;
        tokenToId["VOID"] = 268;
        tokenToId["MAIN"] = 269;
        tokenToId["RETURN"] = 270;
        tokenToId["NEW"] = 271;
        tokenToId["THIS"] = 272;
        tokenToId["PRINTLN"] = 273;
        tokenToId["DOTLENGTH"] = 274;
        tokenToId["STRING"] = 275;
        tokenToId["INT"] = 276;
        tokenToId["BOOLEAN"] = 277;
        tokenToId["CLASS"] = 278;
        tokenToId["LCURLYBRACE"] = 279;
        tokenToId["RCURLYBRACE"] = 280;
        tokenToId["LPAREN"] = 281;
        tokenToId["RPAREN"] = 282;
        tokenToId["LSQUAREBRACKET"] = 283;
        tokenToId["RSQUAREBRACKET"] = 284;
        tokenToId["SEMICOLON"] = 285;
        tokenToId["COMMA"] = 286;
        tokenToId["DOT"] = 287;
        tokenToId["EQUALS"] = 288;
        tokenToId["NOT"] = 289;
        tokenToId["LESS"] = 290;
        tokenToId["AND"] = 291;
        tokenToId["PLUS"] = 292;
        tokenToId["MINUS"] = 293;
        tokenToId["MULTIPLY"] = 294;
        for( auto it = tokenToId.begin(); it != tokenToId.end(); it++ ) {
            idToToken[it->second] = it->first;
        }
    }

    std::map<std::string, int> tokenToId;
    std::map<int, std::string> idToToken;
};
