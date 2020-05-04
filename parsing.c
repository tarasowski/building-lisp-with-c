#include <stdio.h>
#include <stdlib.h>

// we put into quotation marks so it searches the current location first
#include "mpc.h"

// If we are compiling on Windown compile these functions
// # is so called preprocessing, you can include conditions to make your code portable for windows, linux and mac os
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

// Fake readline function
char* readline(cahr* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

// Fake add_history function
void add_history(char* unused) {}

// Otherwise include the editline headers
#else
#include <editline/readline.h>
#endif


int main(int argc, char** argv) {
  // Create parsers
  mpc_parser_t* Number    = mpc_new("number");
  mpc_parser_t* Operator  = mpc_new("operator");
  mpc_parser_t* Expr      = mpc_new("expr");
  mpc_parser_t* Lispy     = mpc_new("lispy");
  
  //  Define them with the following language
  mpca_lang(MPCA_LANG_DEFAULT,
          "                                             \
          number: /-?[0-9]+/ ;                          \
          operator: '+' | '-' | '*' | '/' ;             \
          expr: <number> | '(' <operator> <expr>+ ')' ; \
          lispy: /^/ <operator> <expr>+ /$/ ;           \
          ",
          Number, Operator, Expr, Lispy);
  puts("Lispy Version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");

  while (1) {
  char* input = readline("lispy> ");
  add_history(input);
  mpc_result_t r;
  if(mpc_parse("<stdin>", input, Lispy, &r)) {
  mpc_ast_print(r.output);
  mpc_ast_delete(r.output);
  } else {
  mpc_err_print(r.error);
  mpc_err_delete(r.error);
}
  free(input);
  }
  // Undefine and Delete our Parser
  mpc_cleanup(4, Number, Operator, Expr, Lispy);
  return 0;
}
