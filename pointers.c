#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;
  float d = 1;
  float e = 2;
  float* dpointer = &d;
  float* epointer = &e;
  
  printf("The value of d is %f\n", d);
  printf("The address of d is %p\n",(void*)&d);
  printf("The value of e is %f\n", e);
  printf("The address of e is %p\n",(void*)&e);
  float tempvar = *dpointer;
  *dpointer = *epointer;
  *epointer = tempvar;
  printf("The value of d is %f\n", d);
  printf("The value of e is %f\n", e);
  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);
}
