#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
//#include <editline/history.h>

// Declare a buffer for user input of size 2048
// input is the name of the array
// the array size is 2048 chars
// static is what it makes the array local to this file
static char input[2048];

int main(int argc, char** argv) {
  puts("Lispy version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");

  // (1) always evaluates to true
  while (1) {
  // fputs append \n it's a version of puts
  // stdout and stdin are declared in stdio.h
  //fputs("lispy> ", stdout);
  //fgets(input, 2048, stdin);
  char* input = readline("lispy> ");
  add_history(input);
  // %s means that it will be replaced by whatever argument is passed in next, interepreted as a string
  printf("No you're a %s\n", input);
  // comes from stdlib.h and gets free memory of input
  free(input);
}

  return 0;
}
