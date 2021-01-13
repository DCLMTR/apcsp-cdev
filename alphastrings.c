#include <stdio.h>
#include <string.h>
int main(){
  char str1[27];
  char str2[] = "abcdefghijklmnopqrstuvwxyz";
  char str3[53];
  for(int i = 0; i < 26; i++){
    str1[i] = i+97;
  }
  str1[26] = '\0';
    if(strcmp(str1, str2) == 0)
      printf("the strings are identical\n");
    else
      printf("the strings are different\n");
  for(int i = 0; i < 26; i++){
    str1[i] -= 32;
  }
  if(strcmp(str1, str2) == 0)
    printf("the strings are identical\n");
  else
    printf("the strings are different\n");
  strcpy(str3, str1);
  strcat(str3, str2);
  printf("%s\n%s\n%s\n", str1, str2, str3);
}
