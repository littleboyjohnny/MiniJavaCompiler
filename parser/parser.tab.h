/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    IF = 259,
    ELSE = 260,
    WHILE = 261,
    INTLITERAL = 262,
    _TRUE = 263,
    _FALSE = 264,
    PUBLIC = 265,
    STATIC = 266,
    EXTENDS = 267,
    VOID = 268,
    MAIN = 269,
    RETURN = 270,
    NEW = 271,
    THIS = 272,
    PRINTLN = 273,
    DOTLENGTH = 274,
    STRING = 275,
    INT = 276,
    BOOLEAN = 277,
    CLASS = 278,
    LCURLYBRACE = 279,
    RCURLYBRACE = 280,
    LPAREN = 281,
    RPAREN = 282,
    LSQUAREBRACKET = 283,
    RSQUAREBRACKET = 284,
    SEMICOLON = 285,
    COMMA = 286,
    DOT = 287,
    EQUALS = 288,
    NOT = 289,
    LESS = 290,
    AND = 291,
    PLUS = 292,
    MINUS = 293,
    MULTIPLY = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "parser/parser.y" /* yacc.c:1909  */

	class IGoal* goal;
	class IClassDeclarationS* classDeclarationS;
	class IMainClass* mainClass;
	class IClassDeclaration* classDeclaration;
	class IExtension* extension;
	class IVarDeclarationS* varDeclarationS;
	class IVarDeclaration* varDeclaration;
	class IMethodDeclarationS* methodDeclarationS;
	class IMethodDeclaration* methodDeclaration;
	class IParams* params;
	class IAdditionalParamS* additionalParamS;
	class IAdditionalParam* additionalParam;
	class IType* type;
	class IStatementS* statementS;
	class IStatement* statement;
	class IExpression* expression;
	class IExpressionParamS* expressionParamS;
	class IAdditionalExpressionParamS* additionalExpressionParamS;
	class IAdditionalExpressionParam* additionalExpressionParam;
	class CTerminalIdentifier* terminalIdentifier;
	class CTerminalIntliteral* terminalIntliteral;

#line 118 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
