#include <stdio.h>

int main(int argc, char **argv) {
  int i = 0;
  while (i < 5) {
    i++;
    printf("%i -> Hello, world!\n", i);
  }
  return 0;
}
