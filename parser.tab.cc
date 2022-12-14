// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 15 "parser.y"

  #include <string>
  #include <memory>
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;

  void log(std::string message, std::string text);

  std::unique_ptr<TransUnit> root = std::make_unique<TransUnit>();

#line 58 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 131 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_key_value: // key_value
        value.YY_MOVE_OR_COPY< std::pair<std::string, std::unique_ptr<Expr>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_BRACKET_L: // BRACKET_L
      case symbol_kind::S_BRACKET_L_DOT: // BRACKET_L_DOT
      case symbol_kind::S_BRACKET_R: // BRACKET_R
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_LOR: // LOR
      case symbol_kind::S_LAND: // LAND
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MUL: // MUL
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_PAREN_L: // PAREN_L
      case symbol_kind::S_PAREN_R: // PAREN_R
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_section_header: // section_header
      case symbol_kind::S_subsection_header: // subsection_header
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_l_or_expr: // l_or_expr
      case symbol_kind::S_l_and_expr: // l_and_expr
      case symbol_kind::S_eq_expr: // eq_expr
      case symbol_kind::S_rel_expr: // rel_expr
      case symbol_kind::S_add_expr: // add_expr
      case symbol_kind::S_mul_expr: // mul_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_primary_expr: // primary_expr
        value.YY_MOVE_OR_COPY< std::unique_ptr<Expr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_section: // section
        value.YY_MOVE_OR_COPY< std::unique_ptr<Section> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subsection: // subsection
        value.YY_MOVE_OR_COPY< std::unique_ptr<Subsection> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subsection_body: // subsection_body
      case symbol_kind::S_key_value_list: // key_value_list
        value.YY_MOVE_OR_COPY< std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_args: // func_args
        value.YY_MOVE_OR_COPY< std::vector<std::unique_ptr<Expr>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_section_list: // section_list
        value.YY_MOVE_OR_COPY< std::vector<std::unique_ptr<Section>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_section_body: // section_body
      case symbol_kind::S_subsection_list: // subsection_list
        value.YY_MOVE_OR_COPY< std::vector<std::unique_ptr<Subsection>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_key_value: // key_value
        value.move< std::pair<std::string, std::unique_ptr<Expr>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_BRACKET_L: // BRACKET_L
      case symbol_kind::S_BRACKET_L_DOT: // BRACKET_L_DOT
      case symbol_kind::S_BRACKET_R: // BRACKET_R
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_LOR: // LOR
      case symbol_kind::S_LAND: // LAND
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MUL: // MUL
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_PAREN_L: // PAREN_L
      case symbol_kind::S_PAREN_R: // PAREN_R
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_section_header: // section_header
      case symbol_kind::S_subsection_header: // subsection_header
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_l_or_expr: // l_or_expr
      case symbol_kind::S_l_and_expr: // l_and_expr
      case symbol_kind::S_eq_expr: // eq_expr
      case symbol_kind::S_rel_expr: // rel_expr
      case symbol_kind::S_add_expr: // add_expr
      case symbol_kind::S_mul_expr: // mul_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_primary_expr: // primary_expr
        value.move< std::unique_ptr<Expr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_section: // section
        value.move< std::unique_ptr<Section> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subsection: // subsection
        value.move< std::unique_ptr<Subsection> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subsection_body: // subsection_body
      case symbol_kind::S_key_value_list: // key_value_list
        value.move< std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_args: // func_args
        value.move< std::vector<std::unique_ptr<Expr>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_section_list: // section_list
        value.move< std::vector<std::unique_ptr<Section>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_section_body: // section_body
      case symbol_kind::S_subsection_list: // subsection_list
        value.move< std::vector<std::unique_ptr<Subsection>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_key_value: // key_value
        value.copy< std::pair<std::string, std::unique_ptr<Expr>> > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_BRACKET_L: // BRACKET_L
      case symbol_kind::S_BRACKET_L_DOT: // BRACKET_L_DOT
      case symbol_kind::S_BRACKET_R: // BRACKET_R
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_LOR: // LOR
      case symbol_kind::S_LAND: // LAND
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MUL: // MUL
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_PAREN_L: // PAREN_L
      case symbol_kind::S_PAREN_R: // PAREN_R
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_section_header: // section_header
      case symbol_kind::S_subsection_header: // subsection_header
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_l_or_expr: // l_or_expr
      case symbol_kind::S_l_and_expr: // l_and_expr
      case symbol_kind::S_eq_expr: // eq_expr
      case symbol_kind::S_rel_expr: // rel_expr
      case symbol_kind::S_add_expr: // add_expr
      case symbol_kind::S_mul_expr: // mul_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_primary_expr: // primary_expr
        value.copy< std::unique_ptr<Expr> > (that.value);
        break;

      case symbol_kind::S_section: // section
        value.copy< std::unique_ptr<Section> > (that.value);
        break;

      case symbol_kind::S_subsection: // subsection
        value.copy< std::unique_ptr<Subsection> > (that.value);
        break;

      case symbol_kind::S_subsection_body: // subsection_body
      case symbol_kind::S_key_value_list: // key_value_list
        value.copy< std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > (that.value);
        break;

      case symbol_kind::S_func_args: // func_args
        value.copy< std::vector<std::unique_ptr<Expr>> > (that.value);
        break;

      case symbol_kind::S_section_list: // section_list
        value.copy< std::vector<std::unique_ptr<Section>> > (that.value);
        break;

      case symbol_kind::S_section_body: // section_body
      case symbol_kind::S_subsection_list: // subsection_list
        value.copy< std::vector<std::unique_ptr<Subsection>> > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_key_value: // key_value
        value.move< std::pair<std::string, std::unique_ptr<Expr>> > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_BRACKET_L: // BRACKET_L
      case symbol_kind::S_BRACKET_L_DOT: // BRACKET_L_DOT
      case symbol_kind::S_BRACKET_R: // BRACKET_R
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_LOR: // LOR
      case symbol_kind::S_LAND: // LAND
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MUL: // MUL
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_PAREN_L: // PAREN_L
      case symbol_kind::S_PAREN_R: // PAREN_R
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_section_header: // section_header
      case symbol_kind::S_subsection_header: // subsection_header
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_l_or_expr: // l_or_expr
      case symbol_kind::S_l_and_expr: // l_and_expr
      case symbol_kind::S_eq_expr: // eq_expr
      case symbol_kind::S_rel_expr: // rel_expr
      case symbol_kind::S_add_expr: // add_expr
      case symbol_kind::S_mul_expr: // mul_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_primary_expr: // primary_expr
        value.move< std::unique_ptr<Expr> > (that.value);
        break;

      case symbol_kind::S_section: // section
        value.move< std::unique_ptr<Section> > (that.value);
        break;

      case symbol_kind::S_subsection: // subsection
        value.move< std::unique_ptr<Subsection> > (that.value);
        break;

      case symbol_kind::S_subsection_body: // subsection_body
      case symbol_kind::S_key_value_list: // key_value_list
        value.move< std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > (that.value);
        break;

      case symbol_kind::S_func_args: // func_args
        value.move< std::vector<std::unique_ptr<Expr>> > (that.value);
        break;

      case symbol_kind::S_section_list: // section_list
        value.move< std::vector<std::unique_ptr<Section>> > (that.value);
        break;

      case symbol_kind::S_section_body: // section_body
      case symbol_kind::S_subsection_list: // subsection_list
        value.move< std::vector<std::unique_ptr<Subsection>> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_key_value: // key_value
        yylhs.value.emplace< std::pair<std::string, std::unique_ptr<Expr>> > ();
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_BRACKET_L: // BRACKET_L
      case symbol_kind::S_BRACKET_L_DOT: // BRACKET_L_DOT
      case symbol_kind::S_BRACKET_R: // BRACKET_R
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_LOR: // LOR
      case symbol_kind::S_LAND: // LAND
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MUL: // MUL
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_PAREN_L: // PAREN_L
      case symbol_kind::S_PAREN_R: // PAREN_R
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_section_header: // section_header
      case symbol_kind::S_subsection_header: // subsection_header
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_l_or_expr: // l_or_expr
      case symbol_kind::S_l_and_expr: // l_and_expr
      case symbol_kind::S_eq_expr: // eq_expr
      case symbol_kind::S_rel_expr: // rel_expr
      case symbol_kind::S_add_expr: // add_expr
      case symbol_kind::S_mul_expr: // mul_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_primary_expr: // primary_expr
        yylhs.value.emplace< std::unique_ptr<Expr> > ();
        break;

      case symbol_kind::S_section: // section
        yylhs.value.emplace< std::unique_ptr<Section> > ();
        break;

      case symbol_kind::S_subsection: // subsection
        yylhs.value.emplace< std::unique_ptr<Subsection> > ();
        break;

      case symbol_kind::S_subsection_body: // subsection_body
      case symbol_kind::S_key_value_list: // key_value_list
        yylhs.value.emplace< std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > ();
        break;

      case symbol_kind::S_func_args: // func_args
        yylhs.value.emplace< std::vector<std::unique_ptr<Expr>> > ();
        break;

      case symbol_kind::S_section_list: // section_list
        yylhs.value.emplace< std::vector<std::unique_ptr<Section>> > ();
        break;

      case symbol_kind::S_section_body: // section_body
      case symbol_kind::S_subsection_list: // subsection_list
        yylhs.value.emplace< std::vector<std::unique_ptr<Subsection>> > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // trans_unit: %empty
#line 69 "parser.y"
           {
    }
#line 863 "parser.tab.cc"
    break;

  case 3: // trans_unit: section_list
#line 71 "parser.y"
                  {
      root->sections = std::move(yystack_[0].value.as < std::vector<std::unique_ptr<Section>> > ());
    }
#line 871 "parser.tab.cc"
    break;

  case 4: // section_list: section_list section
#line 76 "parser.y"
                         {
      // log("rule", "section_list -> section_list section");
      yylhs.value.as < std::vector<std::unique_ptr<Section>> > () = std::move(yystack_[1].value.as < std::vector<std::unique_ptr<Section>> > ());
      yylhs.value.as < std::vector<std::unique_ptr<Section>> > ().push_back(std::move(yystack_[0].value.as < std::unique_ptr<Section> > ()));
    }
#line 881 "parser.tab.cc"
    break;

  case 5: // section_list: section
#line 81 "parser.y"
            {
      // log("rule", "section_list -> section");
      yylhs.value.as < std::vector<std::unique_ptr<Section>> > () = std::vector<std::unique_ptr<Section>>();
      yylhs.value.as < std::vector<std::unique_ptr<Section>> > ().push_back(std::move(yystack_[0].value.as < std::unique_ptr<Section> > ()));
    }
#line 891 "parser.tab.cc"
    break;

  case 6: // section: section_header section_body
#line 88 "parser.y"
                                { 
      yylhs.value.as < std::unique_ptr<Section> > () = std::make_unique<Section>();
      yylhs.value.as < std::unique_ptr<Section> > ()->name = yystack_[1].value.as < std::string > ();
      yylhs.value.as < std::unique_ptr<Section> > ()->subsections = std::move(yystack_[0].value.as < std::vector<std::unique_ptr<Subsection>> > ());
    }
#line 901 "parser.tab.cc"
    break;

  case 7: // section_header: BRACKET_L ID BRACKET_R
#line 95 "parser.y"
                            {
      // log("rule", "section_header -> BRACKET_L ID BRACKET_R");
      yylhs.value.as < std::string > () = std::move(yystack_[1].value.as < std::string > ());
    }
#line 910 "parser.tab.cc"
    break;

  case 8: // section_body: %empty
#line 101 "parser.y"
            {
      yylhs.value.as < std::vector<std::unique_ptr<Subsection>> > () = std::vector<std::unique_ptr<Subsection>>();
    }
#line 918 "parser.tab.cc"
    break;

  case 9: // section_body: subsection_list
#line 104 "parser.y"
                    {
      yylhs.value.as < std::vector<std::unique_ptr<Subsection>> > () = std::move(yystack_[0].value.as < std::vector<std::unique_ptr<Subsection>> > ());
    }
#line 926 "parser.tab.cc"
    break;

  case 10: // subsection_list: subsection_list subsection
#line 109 "parser.y"
                                {
      yylhs.value.as < std::vector<std::unique_ptr<Subsection>> > () = std::move(yystack_[1].value.as < std::vector<std::unique_ptr<Subsection>> > ());
      yylhs.value.as < std::vector<std::unique_ptr<Subsection>> > ().push_back(std::move(yystack_[0].value.as < std::unique_ptr<Subsection> > ()));
    }
#line 935 "parser.tab.cc"
    break;

  case 11: // subsection_list: subsection
#line 113 "parser.y"
               { 
      yylhs.value.as < std::vector<std::unique_ptr<Subsection>> > () = std::vector<std::unique_ptr<Subsection>>();
      yylhs.value.as < std::vector<std::unique_ptr<Subsection>> > ().push_back(std::move(yystack_[0].value.as < std::unique_ptr<Subsection> > ()));
    }
#line 944 "parser.tab.cc"
    break;

  case 12: // subsection: subsection_header subsection_body
#line 119 "parser.y"
                                      {
      yylhs.value.as < std::unique_ptr<Subsection> > () = std::make_unique<Subsection>();
      yylhs.value.as < std::unique_ptr<Subsection> > ()->name = yystack_[1].value.as < std::string > ();
      yylhs.value.as < std::unique_ptr<Subsection> > ()->properties = std::move(yystack_[0].value.as < std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > ());
    }
#line 954 "parser.tab.cc"
    break;

  case 13: // subsection_header: BRACKET_L_DOT ID BRACKET_R
#line 126 "parser.y"
                               {
      yylhs.value.as < std::string > () = std::move(yystack_[1].value.as < std::string > ());
    }
#line 962 "parser.tab.cc"
    break;

  case 14: // subsection_body: %empty
#line 131 "parser.y"
           {
      yylhs.value.as < std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > () = std::vector<std::pair<std::string, std::unique_ptr<Expr>>>();
    }
#line 970 "parser.tab.cc"
    break;

  case 15: // subsection_body: key_value_list
#line 134 "parser.y"
                   {
      yylhs.value.as < std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > () = std::move(yystack_[0].value.as < std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > ());
    }
#line 978 "parser.tab.cc"
    break;

  case 16: // key_value_list: key_value_list key_value
#line 139 "parser.y"
                             {
      yylhs.value.as < std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > () = std::move(yystack_[1].value.as < std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > ());
      yylhs.value.as < std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > ().push_back(std::move(yystack_[0].value.as < std::pair<std::string, std::unique_ptr<Expr>> > ()));
    }
#line 987 "parser.tab.cc"
    break;

  case 17: // key_value_list: key_value
#line 143 "parser.y"
               {
      yylhs.value.as < std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > () = std::vector<std::pair<std::string, std::unique_ptr<Expr>>>();
      yylhs.value.as < std::vector<std::pair<std::string, std::unique_ptr<Expr>>> > ().push_back(std::move(yystack_[0].value.as < std::pair<std::string, std::unique_ptr<Expr>> > ()));
    }
#line 996 "parser.tab.cc"
    break;

  case 18: // key_value: ID ASSIGN expr
#line 149 "parser.y"
                   { 
      yylhs.value.as < std::pair<std::string, std::unique_ptr<Expr>> > () = std::make_pair(yystack_[2].value.as < std::string > (), std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ())); 
    }
#line 1004 "parser.tab.cc"
    break;

  case 19: // expr: l_or_expr
#line 154 "parser.y"
              { yylhs.value.as < std::unique_ptr<Expr> > () = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ()); }
#line 1010 "parser.tab.cc"
    break;

  case 20: // l_or_expr: l_and_expr
#line 158 "parser.y"
                 { yylhs.value.as < std::unique_ptr<Expr> > () = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ()); }
#line 1016 "parser.tab.cc"
    break;

  case 21: // l_or_expr: l_or_expr LOR l_and_expr
#line 159 "parser.y"
                               {
        auto tmp = std::make_unique<BinOpExpr>();
        tmp->op = yystack_[1].value.as < std::string > ();
        tmp->lhs = std::move(yystack_[2].value.as < std::unique_ptr<Expr> > ());
        tmp->rhs = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
        yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
      }
#line 1028 "parser.tab.cc"
    break;

  case 22: // l_and_expr: eq_expr
#line 169 "parser.y"
              { yylhs.value.as < std::unique_ptr<Expr> > () = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ()); }
#line 1034 "parser.tab.cc"
    break;

  case 23: // l_and_expr: l_and_expr LAND eq_expr
#line 170 "parser.y"
                              {
        auto tmp = std::make_unique<BinOpExpr>();
        tmp->op = yystack_[1].value.as < std::string > ();
        tmp->lhs = std::move(yystack_[2].value.as < std::unique_ptr<Expr> > ());
        tmp->rhs = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
        yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
      }
#line 1046 "parser.tab.cc"
    break;

  case 24: // eq_expr: rel_expr
#line 180 "parser.y"
             { yylhs.value.as < std::unique_ptr<Expr> > () = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ()); }
#line 1052 "parser.tab.cc"
    break;

  case 25: // eq_expr: eq_expr EQ rel_expr
#line 181 "parser.y"
                        {
        auto tmp = std::make_unique<BinOpExpr>();
        tmp->op = yystack_[1].value.as < std::string > ();
        tmp->lhs = std::move(yystack_[2].value.as < std::unique_ptr<Expr> > ());
        tmp->rhs = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
        yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
      }
#line 1064 "parser.tab.cc"
    break;

  case 26: // eq_expr: eq_expr NE rel_expr
#line 188 "parser.y"
                        {
        auto tmp = std::make_unique<BinOpExpr>();
        tmp->op = yystack_[1].value.as < std::string > ();
        tmp->lhs = std::move(yystack_[2].value.as < std::unique_ptr<Expr> > ());
        tmp->rhs = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
        yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
      }
#line 1076 "parser.tab.cc"
    break;

  case 27: // rel_expr: add_expr
#line 198 "parser.y"
             { yylhs.value.as < std::unique_ptr<Expr> > () = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ()); }
#line 1082 "parser.tab.cc"
    break;

  case 28: // rel_expr: rel_expr LT add_expr
#line 199 "parser.y"
                         {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = yystack_[1].value.as < std::string > ();
      tmp->lhs = std::move(yystack_[2].value.as < std::unique_ptr<Expr> > ());
      tmp->rhs = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
        yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1094 "parser.tab.cc"
    break;

  case 29: // rel_expr: rel_expr GT add_expr
#line 206 "parser.y"
                         {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = yystack_[1].value.as < std::string > ();
      tmp->lhs = std::move(yystack_[2].value.as < std::unique_ptr<Expr> > ());
      tmp->rhs = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
        yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1106 "parser.tab.cc"
    break;

  case 30: // rel_expr: rel_expr LE add_expr
#line 213 "parser.y"
                         {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = yystack_[1].value.as < std::string > ();
      tmp->lhs = std::move(yystack_[2].value.as < std::unique_ptr<Expr> > ());
      tmp->rhs = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
        yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1118 "parser.tab.cc"
    break;

  case 31: // rel_expr: rel_expr GE add_expr
#line 220 "parser.y"
                         {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = yystack_[1].value.as < std::string > ();
      tmp->lhs = std::move(yystack_[2].value.as < std::unique_ptr<Expr> > ());
      tmp->rhs = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
        yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1130 "parser.tab.cc"
    break;

  case 32: // add_expr: mul_expr
#line 229 "parser.y"
             { yylhs.value.as < std::unique_ptr<Expr> > () = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ()); }
#line 1136 "parser.tab.cc"
    break;

  case 33: // add_expr: add_expr PLUS mul_expr
#line 230 "parser.y"
                           {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = yystack_[1].value.as < std::string > ();
      tmp->lhs = std::move(yystack_[2].value.as < std::unique_ptr<Expr> > ());
      tmp->rhs = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
        yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1148 "parser.tab.cc"
    break;

  case 34: // add_expr: add_expr MINUS mul_expr
#line 237 "parser.y"
                            {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = yystack_[1].value.as < std::string > ();
      tmp->lhs = std::move(yystack_[2].value.as < std::unique_ptr<Expr> > ());
      tmp->rhs = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
        yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1160 "parser.tab.cc"
    break;

  case 35: // mul_expr: unary_expr
#line 247 "parser.y"
               {
      yylhs.value.as < std::unique_ptr<Expr> > () = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
    }
#line 1168 "parser.tab.cc"
    break;

  case 36: // mul_expr: mul_expr MUL unary_expr
#line 250 "parser.y"
                            {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = yystack_[1].value.as < std::string > ();
      tmp->lhs = std::move(yystack_[2].value.as < std::unique_ptr<Expr> > ());
      tmp->rhs = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
        yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1180 "parser.tab.cc"
    break;

  case 37: // mul_expr: mul_expr DIV unary_expr
#line 257 "parser.y"
                            {
      auto tmp = std::make_unique<BinOpExpr>();
      tmp->op = yystack_[1].value.as < std::string > ();
      tmp->lhs = std::move(yystack_[2].value.as < std::unique_ptr<Expr> > ());
      tmp->rhs = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
        yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1192 "parser.tab.cc"
    break;

  case 38: // unary_expr: primary_expr
#line 267 "parser.y"
                 {
      yylhs.value.as < std::unique_ptr<Expr> > () = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
    }
#line 1200 "parser.tab.cc"
    break;

  case 39: // unary_expr: MINUS primary_expr
#line 270 "parser.y"
                       {
      auto tmp = std::make_unique<UnaryExpr>();
      tmp->op = yystack_[1].value.as < std::string > ();
      tmp->expr = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
      yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1211 "parser.tab.cc"
    break;

  case 40: // unary_expr: PLUS primary_expr
#line 276 "parser.y"
                      {
      auto tmp = std::make_unique<UnaryExpr>();
      tmp->op = yystack_[1].value.as < std::string > ();
      tmp->expr = std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ());
      yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1222 "parser.tab.cc"
    break;

  case 41: // unary_expr: ID PAREN_L PAREN_R
#line 282 "parser.y"
                       {
      auto tmp = std::make_unique<CallExpr>();
      tmp->name = yystack_[2].value.as < std::string > ();
      yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1232 "parser.tab.cc"
    break;

  case 42: // unary_expr: ID PAREN_L func_args PAREN_R
#line 287 "parser.y"
                                 {
      auto tmp = std::make_unique<CallExpr>();
      tmp->name = yystack_[3].value.as < std::string > ();
      tmp->args = std::move(yystack_[1].value.as < std::vector<std::unique_ptr<Expr>> > ());
      yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1243 "parser.tab.cc"
    break;

  case 43: // func_args: expr
#line 296 "parser.y"
         {
      yylhs.value.as < std::vector<std::unique_ptr<Expr>> > () = std::vector<std::unique_ptr<Expr>>();
      yylhs.value.as < std::vector<std::unique_ptr<Expr>> > ().push_back(std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ()));
    }
#line 1252 "parser.tab.cc"
    break;

  case 44: // func_args: func_args COMMA expr
#line 300 "parser.y"
                         {
      yylhs.value.as < std::vector<std::unique_ptr<Expr>> > () = std::move(yystack_[2].value.as < std::vector<std::unique_ptr<Expr>> > ());
      yylhs.value.as < std::vector<std::unique_ptr<Expr>> > ().push_back(std::move(yystack_[0].value.as < std::unique_ptr<Expr> > ()));
    }
#line 1261 "parser.tab.cc"
    break;

  case 45: // primary_expr: ID
#line 307 "parser.y"
       {
      auto tmp = std::make_unique<IDExpr>();
      tmp->value = std::move(yystack_[0].value.as < std::string > ());
      yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1271 "parser.tab.cc"
    break;

  case 46: // primary_expr: NUMBER
#line 312 "parser.y"
           {
      auto tmp = std::make_unique<NumberExpr>();
      tmp->set_value(yystack_[0].value.as < std::string > ());
      yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1281 "parser.tab.cc"
    break;

  case 47: // primary_expr: STRING
#line 317 "parser.y"
           {
      auto tmp = std::make_unique<StringExpr>();
      tmp->value = yystack_[0].value.as < std::string > ().substr(1, yystack_[0].value.as < std::string > ().size() - 2);
      yylhs.value.as < std::unique_ptr<Expr> > () = static_cast<std::unique_ptr<Expr>>(std::move(tmp));
    }
#line 1291 "parser.tab.cc"
    break;

  case 48: // primary_expr: PAREN_L expr PAREN_R
#line 322 "parser.y"
                         {
      yylhs.value.as < std::unique_ptr<Expr> > () = std::move(yystack_[1].value.as < std::unique_ptr<Expr> > ());
    }
#line 1299 "parser.tab.cc"
    break;


#line 1303 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -29;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
       8,    16,    32,     8,   -29,    28,    29,   -29,   -29,    34,
     -29,    28,   -29,    36,   -29,    42,   -29,    46,   -29,    36,
     -29,   -29,     9,   -29,   -29,    31,    15,    15,     9,   -29,
     -29,    43,    44,    -3,   -11,    -5,     3,   -29,   -29,    -2,
     -29,   -29,   -29,    35,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,   -29,   -29,   -16,   -29,
      44,    -3,   -11,   -11,    -5,    -5,    -5,    -5,     3,     3,
     -29,   -29,   -29,     9,   -29
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     0,     3,     5,     8,     0,     1,     4,     0,
       6,     9,    11,    14,     7,     0,    10,     0,    12,    15,
      17,    13,     0,    16,    47,    45,     0,     0,     0,    46,
      18,    19,    20,    22,    24,    27,    32,    35,    38,     0,
      45,    40,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    43,     0,    48,
      21,    23,    25,    26,    28,    29,    30,    31,    33,    34,
      36,    37,    42,     0,    44
  };

  const signed char
  parser::yypgoto_[] =
  {
     -29,   -29,   -29,    52,   -29,   -29,   -29,    48,   -29,   -29,
     -29,    38,   -28,   -29,    17,    18,   -17,    -8,   -18,    -7,
     -29,    23
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     5,    10,    11,    12,    13,    18,
      19,    20,    30,    31,    32,    33,    34,    35,    36,    37,
      58,    38
  };

  const signed char
  parser::yytable_[] =
  {
      43,    24,    46,    48,    49,    50,    51,    72,    25,    73,
      47,    57,    24,    52,    53,     1,    26,    27,    24,    25,
      28,    56,    29,    54,    55,    40,     6,    26,    27,    62,
      63,    28,     7,    29,    68,    69,     9,    28,    14,    29,
      64,    65,    66,    67,    15,    74,    17,    70,    71,    41,
      42,    21,    22,    39,    44,     8,    45,    23,    59,    16,
       0,    60,     0,    61
  };

  const signed char
  parser::yycheck_[] =
  {
      28,     3,     5,    14,    15,    16,    17,    23,    10,    25,
      13,    39,     3,    18,    19,     7,    18,    19,     3,    10,
      22,    23,    24,    20,    21,    10,    10,    18,    19,    46,
      47,    22,     0,    24,    52,    53,     8,    22,     9,    24,
      48,    49,    50,    51,    10,    73,    10,    54,    55,    26,
      27,     9,     6,    22,    11,     3,    12,    19,    23,    11,
      -1,    44,    -1,    45
  };

  const signed char
  parser::yystos_[] =
  {
       0,     7,    27,    28,    29,    30,    10,     0,    29,     8,
      31,    32,    33,    34,     9,    10,    33,    10,    35,    36,
      37,     9,     6,    37,     3,    10,    18,    19,    22,    24,
      38,    39,    40,    41,    42,    43,    44,    45,    47,    22,
      10,    47,    47,    38,    11,    12,     5,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    23,    38,    46,    23,
      40,    41,    42,    42,    43,    43,    43,    43,    44,    44,
      45,    45,    23,    25,    38
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    26,    27,    27,    28,    28,    29,    30,    31,    31,
      32,    32,    33,    34,    35,    35,    36,    36,    37,    38,
      39,    39,    40,    40,    41,    41,    41,    42,    42,    42,
      42,    42,    43,    43,    43,    44,    44,    44,    45,    45,
      45,    45,    45,    46,    46,    47,    47,    47,    47
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     1,     2,     1,     2,     3,     0,     1,
       2,     1,     2,     3,     0,     1,     2,     1,     3,     1,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     2,
       2,     3,     4,     1,     3,     1,     1,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "DOT", "EQ",
  "ASSIGN", "BRACKET_L", "BRACKET_L_DOT", "BRACKET_R", "ID", "LOR", "LAND",
  "NE", "LT", "GT", "LE", "GE", "PLUS", "MINUS", "MUL", "DIV", "PAREN_L",
  "PAREN_R", "NUMBER", "COMMA", "$accept", "trans_unit", "section_list",
  "section", "section_header", "section_body", "subsection_list",
  "subsection", "subsection_header", "subsection_body", "key_value_list",
  "key_value", "expr", "l_or_expr", "l_and_expr", "eq_expr", "rel_expr",
  "add_expr", "mul_expr", "unary_expr", "func_args", "primary_expr", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    69,    69,    71,    76,    81,    88,    95,   101,   104,
     109,   113,   119,   126,   131,   134,   139,   143,   149,   154,
     158,   159,   169,   170,   180,   181,   188,   198,   199,   206,
     213,   220,   229,   230,   237,   247,   250,   257,   267,   270,
     276,   282,   287,   296,   300,   307,   312,   317,   322
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1654 "parser.tab.cc"

#line 326 "parser.y"
