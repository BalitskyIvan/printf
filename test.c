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
	// char *c = "gjgjgjhgjhgiy";
	// ft_printf ("%*.20s \n", 30, c);
	// printf ("%*.20s \n", 30, c);
	// ft_printf ("%-50.5s \n", c);
	// printf ("%-50.5s \n", c);
	// int c = 999;
	// ft_printf ("%*.20d \n", 30, c);
	// printf ("%*.20d \n", 30, c);
	// ft_printf ("%-50.5d \n", c);
	// printf ("%-50.5d \n", c);
	// int c = 999;
	// ft_printf ("%*.20i \n", 30, c);
	// printf ("%*.20i \n", 30, c);
	// ft_printf ("%-50.5i \n", c);
	// printf ("%-50.5i \n", c);
	// int c = 999;
	// ft_printf ("%*.20d \n", 30, c);
	// printf ("%*.20d \n", 30, c);
	// ft_printf ("%-50.5d \n", c);
	// printf ("%-50.5d \n", c);
	// int c = 999;
	// ft_printf ("%*.20u \n", 30, &c);
	// printf ("%*.20u \n", 30, &c);
	// ft_printf ("%50.5u\n", &c);
	// printf ("%50.5u\n", &c);
	// int c = 999;
	// ft_printf ("%*.20X \n", 30, &c);
	// printf ("%*.20x \n", 30, &c);
	// ft_printf ("%50.5X\n", &c);
	// printf ("%50.5x\n", &c);
	int c = 43435;
	printf("st17 %0.*d\n", 3, 0);
	printf("st17 %30.*20d\n",20, 3);

//	ft_printf ("%50.5%x\n");
	// printf ("%*10.20%     rt\n", -30);
	// printf ("%50.5%%\n");
   //printf("\n%.3f", val); 
  	//printf("\n%d\n", val); 
   return 0; 
}