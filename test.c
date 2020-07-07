#include <stdio.h>
#include "./includes/printf.h"

int main()
{
	int c = 'a';
	write(0, "testc\n\0", 6);
	//ft_printf("%%%;cugyug\n", c);
	// ft_printf("%30c\n", c);
	// ft_printf("%-30c\n", c);
	
	write(0, "testcend\0", 9);
	printf("\n +++++++++++ TEST PRINaT CHAR ++++++++++++++ \n");
	printf("%-050d\n", c);
	//printf("%30c\n", c);
//	printf("%-30c\n", c);
	printf(" ------------ TEST PRINT CHAR END -------------- \n");
	return (0);
}