#include <stdio.h>

static char input[4096];

int main(int argc, char** argv){
  puts("RML v0.0.2.0\nPress Ctrl+C to exit");

  while(1){
    fputs("rml > ", stdout);
    fgets(input, 4096, stdin);
    printf("Input: %s", input);
  }
}
