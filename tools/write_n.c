#include "../includes/printf.h"

void	write_n(int *n, int count)
{
	printf("COUNT: %d \n", count);
	*n = count;
}