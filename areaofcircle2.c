#include <stdio.h>
#include <math.h>
// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
void areaOfCircle(int lower, int higher)
{
  float area;
  if(lower < 0 || higher < 0) {
   char input[256];
    printf("Input Lower Bound ");
    while (1)
    {
    fgets(input, 256, stdin);
    sscanf(input, "%d", &lower);
    if(lower > 0) break;
    printf("Please enter a valid number ");
    }
    printf("Input Upper Bound ");
    while(1)
    {
    fgets(input, 256, stdin);
    sscanf(input, "%d", &higher);
    if(higher > 0) break;
    printf("Please enter a valid number ");
    }
  }
  if(lower < higher){
    for(int i = lower; i <= higher; i++){
      area = i*i*M_PI;
      printf("area of radius %d = %f\n", i, area);
    }
  }
}



int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  if(argc != 3 && argc != 1){
    printf("please enter two integers\n");
    return 1;
  }
  int start = -1, end = -1;
  if(argc > 1){
  int found = sscanf(argv[1], "%d", &start);
  if(found != 1){
    printf("first argument is not an integer\n");
    return 1;
  }
  found = sscanf(argv[2], "%d", &end);
  if(found != 1){
    printf("second argument is not an integer\n");
    return 1;
  }
  if(argc > 0){
    if(start < 0 || end < 0){
      printf("do not enter negative numbers\n");
      return 1;
    }
  }
  }
  // add your code below to call areaOfCircle function with values between
  // start and end
  areaOfCircle(start, end);
}
