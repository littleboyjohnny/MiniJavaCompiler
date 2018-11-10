cmake_minimum_required( VERSION 3.10 )

project( MiniJavaCompiler )

set( CMAKE_CXX_STANDARD 17 )

#include_directories( $ENV{GTEST_PATH}/googletest/include $ENV{GTEST_PATH}/googletest )

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

#========================= GTest Section =====================================
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(lexertests tests/LexerTests.cpp )
target_link_libraries(lexertests gtest_main liblexer)

add_executable(parsertests tests/ParserTests.cpp)
target_link_libraries(parsertests gtest_main libparser)
#add_test(NAME example_test COMMAND example)
#========================= GTest Section =====================================

# создаем исполняемый фаил - берет имя фаила как параметр командной строки и отрисовывает AST в фаил build/ast.jpg
set( ASTBUILDER_SRC astBuilder.cpp AST/ASTBuilder.cpp AST/ASTVisualiser.cpp )
add_executable( AstBuilder ${ASTBUILDER_SRC} )
target_link_libraries( AstBuilder liblexer libparser )
