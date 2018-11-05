cmake_minimum_required( VERSION 3.12 )

project( MiniJavaCompiler )

set( CMAKE_CXX_STANDARD 17 )

# директория для результатов работы flex и bison и прочего
set( PROJECT_BUILD_DIR ${CMAKE_HOME_DIRECTORY}/build )
file( MAKE_DIRECTORY ${PROJECT_BUILD_DIR} )
include_directories( ${PROJECT_BUILD_DIR} )

# команда очистки предыдущей директории
add_custom_target(
        CleanBuild
        COMMAND rm -rf ${PROJECT_BUILD_DIR}/*
)

# дополнительные директории, относительно которых ide ищет заголовочные фаилы
include_directories( ${CMAKE_HOME_DIRECTORY}/lexer )
include_directories( ${CMAKE_HOME_DIRECTORY}/parser )
include_directories( ${CMAKE_HOME_DIRECTORY}/AST )

# генерируем лексический анализатор flex'ом
add_custom_command(
        OUTPUT ${PROJECT_BUILD_DIR}/lex.yy.cpp
        COMMAND flex -o ${PROJECT_BUILD_DIR}/lex.yy.cpp ${CMAKE_HOME_DIRECTORY}/lexer/lexer.lex
        DEPENDS lexer/lexer.lex
)

# генерируем синтаксический анализатор bison'ом
add_custom_command(
        OUTPUT ${PROJECT_BUILD_DIR}/parser.tab.hpp ${PROJECT_BUILD_DIR}/parser.tab.cpp
        COMMAND bison -o ${PROJECT_BUILD_DIR}/parser.tab.cpp -d ${CMAKE_HOME_DIRECTORY}/parser/parser.y
        DEPENDS parser/parser.y
)

# создаем библиотеку с одной функцией - yylex и переменными положения токена
set( LEXER_SRC lexer/lexer.cpp ${PROJECT_BUILD_DIR}/lex.yy.cpp ${PROJECT_BUILD_DIR}/parser.tab.cpp )
add_library( liblexer ${LEXER_SRC} )

# создаем библиотеку с одной функцией - yyparse
set( PARSER_SRC parser/parser.cpp ${PROJECT_BUILD_DIR}/parser.tab.cpp )
add_library( libparser ${PARSER_SRC} )

# создаем исполняемый фаил - берет имя фаила как параметр командной строки и отрисовывает AST в фаил build/ast.jpg
set( ASTBUILDER_SRC astBuilder.cpp AST/ASTBuilder.cpp AST/ASTVisualiser.cpp )
add_executable( AstBuilder ${ASTBUILDER_SRC} )
target_link_libraries( AstBuilder liblexer libparser )
