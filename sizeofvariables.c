#include<stdio.h>

int main()
{
  int a = 545;
  char c = 'b';
  float f = 1.234;
  double d = 5.678;
  unsigned int a2 = 111;
  short int a3 = 1223;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));
  printf("char b value: %c and size: %lu bytes\n", c, sizeof(c));
  printf("float f value: %f and size: %lu bytes\n", f, sizeof(f));
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));
  printf("unsigned int a2 value: %d and size %lu bytes\n", a2, sizeof(a2));
  printf("short float f2 value: %d and size %lu bytes\n", a3, sizeof(a3));
}

