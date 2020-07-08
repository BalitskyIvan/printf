#include <stdio.h>
#include "./includes/printf.h"

int main() { 
   int val = 9999;
   int a = 8787;
   printf("The value o %d%nval : ", a, &val); 
  	printf("\n%d", val); 
   return 0; 
}