/* This file has been modified to make printd operate in a safe manner.
   I have also cleaned it up a little, I renamed the char buffer to input and i added '#include<stdio.h>'
   All that was needed to make printf secure, was to add a "%s" before the input. %s makes printf
   interperet the following input as a string, no matter what it contains.*/

#include<stdio.h>

int main(void)

{
  char input [32];
  
  printf("Enter your name: ");
  fgets(input,0x20,stdin);
  printf("Hello ");
  printf("%s", input);
  putchar(10);
  return 0;
}

