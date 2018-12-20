// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../parser/parser.h"

#include <stdio.h>
#include <vector>
#include <string>

void printInfo( std::string file ) {
    freopen( file.c_str(), "r", stdin );

    printf("\n\n\n\n\n%s\n", file.c_str());
    IAcceptable * goal = nullptr;
    yyparse( goal, stdout );
}

int main( int argc, char** argv ) {
    std::vector<std::string> files {"tests/inputs/badsamples/LC_1.java",    
                                    "tests/inputs/badsamples/TC_1a.java",
                                    "tests/inputs/badsamples/TC_2a.java",
                                    "tests/inputs/badsamples/TC_3a.java",
                                    "tests/inputs/badsamples/TC_3b.java",
                                    "tests/inputs/badsamples/TC_4a.java",
                                    "tests/inputs/badsamples/TC_4b.java",
                                    "tests/inputs/badsamples/TC_5a.java",
                                    "tests/inputs/badsamples/TC_6a.java",
                                    "tests/inputs/badsamples/TC_7b.java",
                                    "tests/inputs/badsamples/TC_7c.java",
                                    "tests/inputs/badsamples/TC_8a.java",
                                    "tests/inputs/badsamples/TC_9a.java",
                                    "tests/inputs/badsamples/TC_9a_2.java",
                                    "tests/inputs/badsamples/TC_11a.java",
                                    "tests/inputs/badsamples/TC_12b.java",
                                    "tests/inputs/badsamples/TC_13a.java",
                                    "tests/inputs/badsamples/TC_13b.java",
                                    "tests/inputs/badsamples/TC_13c.java",
                                    "tests/inputs/badsamples/TC_bonus1.java"};
    for (int i = 0; i < files.size(); i++) {
        printInfo(files[i]);
    }
}