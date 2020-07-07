#include <stdio.h>
#include "./includes/printf.h"

int main()
{
	int c = -666;
	printf("\n +++++++++++ TEST PRINaT CHAR ++++++++++++++ \n");
	ft_printf("%;-79;%%u\n", c);
	//printf("%30c\n", c);
	//printf("%-30c\n", c);
	printf(" ------------ TEST PRINT CHAR END -------------- \n");
	return (0);
}