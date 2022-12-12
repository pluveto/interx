
%skeleton "lalr1.cc"
%require "3.8.1"
%header
%language "c++"

%define api.value.type variant
%define api.token.constructor
%define parse.trace

%code requires{
	#include "ast.h"
}

%code  {
  #include <string>
  #include <memory>
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;

  void log(std::string message, std::string text);

  std::unique_ptr<TransUnit> root = std::make_unique<TransUnit>();
}

%token <std::string> STRING
  DOT
  EQ
  ASSIGN
  BRACKET_L
  BRACKET_L_DOT
  BRACKET_R
  ID
  LOR
  LAND
  NE
  LT
  GT
  LE
  GE
  PLUS
  MINUS
  MUL
  DIV
  PAREN_L
  PAREN_R
  NUMBER
  COMMA

%token QUIT 0 "end of file"

%type <std::vector<std::unique_ptr<Section>>> section_list
%type <std::unique_ptr<Section>> section
%type <std::string> section_header
%type <std::vector<std::unique_ptr<Subsection>>> section_body
%type <std::vector<std::unique_ptr<Subsection>>> subsection_list
%type <std::unique_ptr<Subsection>> subsection
%type <std::string> subsection_header
%type <std::vector<std::pair<std::string, std::unique_ptr<Expr>>>> subsection_body
%type <std::vector<std::pair<std::string, std::unique_ptr<Expr>>>> key_value_list
%type <std::pair<std::string, std::unique_ptr<Expr>>> key_value
%type <std::unique_ptr<Expr>> expr add_expr eq_expr l_and_expr l_or_expr mul_expr primary_expr rel_expr unary_expr
%type <std::vector<std::unique_ptr<Expr>>> func_args

%%

trans_unit
  : %empty {
    }
  | section_list  {
      root->sections = std::move($1);
    };

section_list
  : section_list section {
      // log("rule", "section_list -> section_list section");
      $$ = std::move($1);
      $$.push_back(std::move($2));
    }
  | section {
      // log("rule", "section_list -> section");
      $$ = std::vector<std::unique_ptr<Section>>();
      $$.push_back(std::move($1));
    };

section
  : section_header section_body { 
      $$ = std::make_unique<Section>();
      $$->name = $1;
      $$->subsections = std::move($2);
    };

section_header
  : BRACKET_L ID BRACKET_R  {
      // log("rule", "section_header -> BRACKET_L ID BRACKET_R");
      $$ = std::move($2);
    };

section_body
  : %empty  {
      $$ = std::vector<std::unique_ptr<Subsection>>();
    };
  | subsection_list {
      $$ = std::move($1);
    };

subsection_list
  : subsection_list subsection  {
      $$ = std::move($1);
      $$.push_back(std::move($2));
    };
  | subsection { 
      $$ = std::vector<std::unique_ptr<Subsection>>();
      $$.push_back(std::move($1));
    };

subsection
  : subsection_header subsection_body {
      $$ = std::make_unique<Subsection>();
      $$->name = $1;
      $$->properties = std::move($2);
    };

subsection_header
  : BRACKET_L_DOT ID BRACKET_R {
      $$ = std::move($2);
    };

subsection_body
  : %empty {
      $$ = std::vector<std::pair<std::string, std::unique_ptr<Expr>>>();
    };
  | key_value_list {
      $$ = std::move($1);
    };

key_value_list
  : key_value_list key_value {
      $$ = std::move($1);
      $$.push_back(std::move($2));
    };
  | key_value  {
      $$ = std::vector<std::pair<std::string, std::unique_ptr<Expr>>>();
      $$.push_back(std::move($1));
    };

key_value
  : ID ASSIGN expr { 
      $$ = std::make_pair($1, std::move($3)); 
    };

expr
  : l_or_expr { $$ = std::move($1); }
  ;

l_or_expr
    : l_and_expr { $$ = std::move($1); }
    | l_or_expr LOR l_and_expr {
        auto tmp = std::make_unique<BinOpExpr>();
        tmp->op = $2;
        tmp->lhs = std::move($1);
        tmp->rhs = std::move($3);
        $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
      }
    ;

l_and_expr
    : eq_expr { $$ = std::move($1); }
    | l_and_expr LAND eq_expr {
        auto tmp = std::make_unique<BinOpExpr>();
        tmp->op = $2;
        tmp->lhs = std::move($1);
        tmp->rhs = std::move($3);
        $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
      }
    ;

eq_expr
  : rel_expr { $$ = std::move($1); }
  | eq_expr EQ rel_expr {
        auto tmp = std::make_unique<BinOpExpr>();
        tmp->op = $2;
        tmp->lhs = std::move($1);
        tmp->rhs = std::move($3);
        $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
      }
  | eq_expr NE rel_expr {
        auto tmp = std::make_unique<BinOpExpr>();
        tmp->op = $2;
        tmp->lhs = std::move($1);
        tmp->rhs = std::move($3);
        $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
      }
  ;

rel_expr
  : add_expr { $$ = std::move($1); }
  | rel_expr LT add_expr {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = $2;
      tmp->lhs = std::move($1);
      tmp->rhs = std::move($3);
        $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  | rel_expr GT add_expr {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = $2;
      tmp->lhs = std::move($1);
      tmp->rhs = std::move($3);
        $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  | rel_expr LE add_expr {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = $2;
      tmp->lhs = std::move($1);
      tmp->rhs = std::move($3);
        $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  | rel_expr GE add_expr {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = $2;
      tmp->lhs = std::move($1);
      tmp->rhs = std::move($3);
        $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  ;
add_expr
  : mul_expr { $$ = std::move($1); }
  | add_expr PLUS mul_expr {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = $2;
      tmp->lhs = std::move($1);
      tmp->rhs = std::move($3);
        $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  | add_expr MINUS mul_expr {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = $2;
      tmp->lhs = std::move($1);
      tmp->rhs = std::move($3);
        $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  ;

mul_expr
  : unary_expr {
      $$ = std::move($1);
    }
  | mul_expr MUL unary_expr {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = $2;
      tmp->lhs = std::move($1);
      tmp->rhs = std::move($3);
        $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  | mul_expr DIV unary_expr {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = $2;
      tmp->lhs = std::move($1);
      tmp->rhs = std::move($3);
        $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  ;

unary_expr
  : primary_expr {
      $$ = std::move($1);
    }
  | MINUS primary_expr {
      auto tmp = std::make_unique<UnaryExpr>();
      tmp->op = $1;
      tmp->expr = std::move($2);
      $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  | PLUS primary_expr {
      auto tmp = std::make_unique<UnaryExpr>();
      tmp->op = $1;
      tmp->expr = std::move($2);
      $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  | ID PAREN_L PAREN_R {
      auto tmp = std::make_unique<CallExpr>();
      tmp->name = $1;
      $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  | ID PAREN_L func_args PAREN_R {
      auto tmp = std::make_unique<CallExpr>();
      tmp->name = $1;
      tmp->args = std::move($3);
      $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  ;

func_args
  : expr {
      $$ = std::vector<std::unique_ptr<Expr>>();
      $$.push_back(std::move($1));
    }
  | func_args COMMA expr {
      $$ = std::move($1);
      $$.push_back(std::move($3));
    }
  ;

primary_expr
  : ID {
      auto tmp = std::make_unique<IDExpr>();
      tmp->value = std::move($1);
      $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  | NUMBER {
      auto tmp = std::make_unique<NumberExpr>();
      tmp->set_value($1);
      $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  | STRING {
      auto tmp = std::make_unique<StringExpr>();
      tmp->value = $1.substr(1, $1.size() - 2);
      $$ = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
  | PAREN_L expr PAREN_R {
      $$ = std::move($2);
    }
  ;
%%