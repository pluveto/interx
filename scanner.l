%top{
    #include "parser.tab.hh"
    #define YY_DECL yy::parser::symbol_type yylex()
    void log(std::string message, std::string text){
#ifdef DEBUG
        std::cout << message << ": " << text << std::endl;
#endif
    }
}

%option noyywrap nounput batch noinput

%%

\"[^\"]*\"                      { log("token=STRING", yytext); return yy::parser::make_STRING(yytext);}
\'[^\']*\'                      { log("token=STRING", yytext); return yy::parser::make_STRING(yytext);}
[0-9]+(\.[0-9]+)?               { log("token=NUMBER", yytext); return yy::parser::make_NUMBER(yytext);}


"or"        { log("token=LOR", yytext); return yy::parser::make_LOR(yytext); }
"and"       { log("token=LAND", yytext); return yy::parser::make_LAND(yytext); }
"eq"        { log("token=EQ", yytext); return yy::parser::make_EQ(yytext); }
"ne"        { log("token=NE", yytext); return yy::parser::make_NE(yytext); }
">"         { log("token=GT", yytext); return yy::parser::make_GT(yytext); }
"<"         { log("token=LT", yytext); return yy::parser::make_LT(yytext); }
">="        { log("token=GE", yytext); return yy::parser::make_GE(yytext); }
"<="        { log("token=LE", yytext); return yy::parser::make_LE(yytext); }
"+"         { log("token=PLUS", yytext); return yy::parser::make_PLUS(yytext); }
"-"         { log("token=MINUS", yytext); return yy::parser::make_MINUS(yytext); }
"*"         { log("token=MUL", yytext); return yy::parser::make_MUL(yytext); }
"/"         { log("token=DIV", yytext); return yy::parser::make_DIV(yytext); }
"("         { log("token=PAREN_L", yytext); return yy::parser::make_PAREN_L(yytext); }
")"         { log("token=PAREN_R", yytext); return yy::parser::make_PAREN_R(yytext); }
","         { log("token=COMMA", yytext); return yy::parser::make_COMMA(yytext); }

$?[A-Za-z_][A-Za-z0-9_]*        { log("token=ID", yytext); return yy::parser::make_ID(yytext); }


=           { log("token=ASSIGN", yytext); return yy::parser::make_ASSIGN(yytext); }
\.          { log("token=DOT", yytext); return yy::parser::make_DOT(yytext); }
[\[][\.]    { log("token=BRACKET_L_DOT", yytext);  return yy::parser::make_BRACKET_L_DOT(yytext); }
[\[]        { log("token=BRACKET_L", yytext); return yy::parser::make_BRACKET_L(yytext); }
[\]]        { log("token=BRACKET_R", yytext); return yy::parser::make_BRACKET_R(yytext); }
[\n]		{ log("token=NEWLINE", "\\n"); }
[ \t\r]		{ log("token=WHITESPACE", yytext); }
<<EOF>>     { return yy::parser::make_QUIT(); }

%%
