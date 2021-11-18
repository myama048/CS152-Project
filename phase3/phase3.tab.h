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

#ifndef YY_YY_PHASE3_TAB_H_INCLUDED
# define YY_YY_PHASE3_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "phase3.y" /* yacc.c:1909  */

	struct Info {
	  char *name;
	  int value;
	  int type;
	  //Info() {};
   };

#line 53 "phase3.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BEGIN_PARAMS = 258,
    END_PARAMS = 259,
    BEGIN_LOCALS = 260,
    END_LOCALS = 261,
    BEGIN_BODY = 262,
    END_BODY = 263,
    FUNCTION = 264,
    RETURN = 265,
    MAIN = 266,
    L_SQUARE_BRACKET = 267,
    R_SQUARE_BRACKET = 268,
    INTEGER = 269,
    ARRAY = 270,
    OF = 271,
    IF = 272,
    THEN = 273,
    ENDIF = 274,
    ELSE = 275,
    WHILE = 276,
    DO = 277,
    BEGINLOOP = 278,
    ENDLOOP = 279,
    CONTINUE = 280,
    READ = 281,
    WRITE = 282,
    TRUE = 283,
    FALSE = 284,
    AND = 285,
    OR = 286,
    NOT = 287,
    ASSIGN = 288,
    SUB = 289,
    ADD = 290,
    MULT = 291,
    DIV = 292,
    MOD = 293,
    EQ = 294,
    NEQ = 295,
    LT = 296,
    GT = 297,
    LTE = 298,
    GTE = 299,
    SEMICOLON = 300,
    COLON = 301,
    COMMA = 302,
    L_PAREN = 303,
    R_PAREN = 304,
    NUMBER = 305,
    IDENT = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 51 "phase3.y" /* yacc.c:1909  */

  int num_val;
  char *op_val;
  Info* info;

#line 123 "phase3.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PHASE3_TAB_H_INCLUDED  */
