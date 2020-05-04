#include <stdio.h>
#include <math.h>

int count = 10;
char last_initail = 'T';
int age = 36;
long age_of_universe = 13798000000;
float liters_per_print = 0.568f;
double speed_of_swallow = 0.01072896;

int add_together(int x, int y) {
  int result = x + y;
  return result;
}

// Structures are used to declare new types.
// Structures are several variables bundled together into a single package
typedef struct Point {
  float x;
  float y;
} point;

point p = {.x = 0.10, .y = 0.50};

// Pointer is a variation on a normal type where the type name is suffixed with an asteric
// int* or char**

// Strings
char* str = "Hello World";

int x = 50;


int main(int argc, char** argv) {
  puts("Hello world!");
  int added = add_together(10, 18);
  float length = sqrt(p.x * p.x + p.y * p.y);
  printf("Result %f", length);
  puts(str);
  if (x > 10 && x < 100) {
    puts("x is greater than 10 and less than 100!");
  } else {
    puts("x is less than 11 or greater than 99!");
  }
  while (x > 0) {
    puts("Loop iteration");
    x = x - 1;
} 
  for (int i = 0; i < 10; i++) {
    puts("Loop iteration from for loop");
}
  return 0;
}



