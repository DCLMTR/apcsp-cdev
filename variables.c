#include <stdio.h>

int main()
{
  int a;
  int b = 3;
  int c;

  a = 2;
  c = a + b;
  printf("Sum of %d and %d is %d\n", a, b, c);
  int a2 = a;
  a = c;
  c = a2;
  printf("a equals %d and b equals %d and c equals %d\n", a, b, c);
}
