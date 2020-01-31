#include <stdio.h>

int print_hello_n_times(int n);

int main(int argc, char **argv) {
  print_hello_n_times(7);
  return 0;
}

int print_hello_n_times(int n){
  for (int i; i < n; i++) {
    puts("Hello, world!");
  }
  return 0; 
}
