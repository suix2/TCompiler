union YYSTYPE{
    int pos;
    int ival;
    char cval;
    std::string *sval;
    };
extern YYSTYPE yylval;

# define ID 257
# define STRING 258
# define INT 259
# define COMMA 260
# define COLON 261
# define SEMICOLON 262
# define LPAREN 263
# define RPAREN 264
# define LBRACK 265
# define RBRACK 266
# define LBRACE 267
# define RBRACE 268
# define DOT 269
# define PLUS 270
# define MINUS 271
# define TIMES 272
# define DIVIDE 273
# define EQ 274
# define NEQ 275
# define LT 276
# define LE 277
# define GT 278
# define GE 279
# define AND 280
# define OR 281
# define ASSIGN 282
# define ARRAY 283
# define IF 284
# define CONTINUE 285
# define ELSE 286
# define WHILE 287
# define FOR 288
# define RETURN 289
# define CHAR 290
# define SIZEOF 291
# define TYPEDEF 292
# define STRUCT 293
# define SWITCH 294
# define CASE 295
# define BREAK 296
# define DEFAULT 297
# define DEFINE 298
# define INCLUDE 299
# define NOT 300

