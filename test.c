#include <stdio.h>
#include "./includes/printf.h"

int main() {
	// TEST PRINT CHAR
	// int d = 999;
	// char c = 'a';
	// ft_printf ("Width trick: %*.20d \n", 30, 10);
	// printf ("Width trick: %*;'.020d \n", 30, 10);
	// ft_printf ("Width trick: %*10.20d \n", 30, 10);
	// printf ("Width trick: %*10.20d \n", 30, 10);
	// printf("%*)10c\n", c);
	char *c = "gjgjgjhgjhgiy";
	ft_printf ("p%*.20s \n", 30, c);
	printf ("%*.20s \n", 30, c);
	ft_printf ("p%5.5s \n", c);
	printf ("%5.5s \n", c);
   //printf("\n%.3f", val); 
  	//printf("\n%d\n", val); 
   return 0; 
}