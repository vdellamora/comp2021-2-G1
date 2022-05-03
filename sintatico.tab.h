/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    letter = 258,                  /* letter  */
    id = 259,                      /* id  */
    digit = 260,                   /* digit  */
    integer = 261,                 /* integer  */
    tp_inteiro = 262,              /* tp_inteiro  */
    tp_vazio = 263,                /* tp_vazio  */
    op_add = 264,                  /* op_add  */
    op_sub = 265,                  /* op_sub  */
    op_mul = 266,                  /* op_mul  */
    op_div = 267,                  /* op_div  */
    op_igual = 268,                /* op_igual  */
    op_maig = 269,                 /* op_maig  */
    op_meig = 270,                 /* op_meig  */
    op_maior = 271,                /* op_maior  */
    op_menor = 272,                /* op_menor  */
    op_diff = 273,                 /* op_diff  */
    op_atr = 274,                  /* op_atr  */
    op_virgula = 275,              /* op_virgula  */
    op_pvirgula = 276,             /* op_pvirgula  */
    cmd_if = 277,                  /* cmd_if  */
    cmd_else = 278,                /* cmd_else  */
    cmd_while = 279,               /* cmd_while  */
    cmd_return = 280,              /* cmd_return  */
    parent_esq = 281,              /* parent_esq  */
    parent_dir = 282,              /* parent_dir  */
    colch_esq = 283,               /* colch_esq  */
    colch_dir = 284,               /* colch_dir  */
    chave_esq = 285,               /* chave_esq  */
    chave_dir = 286,               /* chave_dir  */
    comment = 287                  /* comment  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "sintatico.y"

    struct Token{
        int linha, coluna, escopo;
        char nome[30];
    } token;

#line 103 "sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
