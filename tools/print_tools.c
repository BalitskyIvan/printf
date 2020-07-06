#include "../includes/printf.h"

void print_whitespaces(int count, int arg_size)
{
	count -= arg_size;
	while (count > 0)
	{
		ft_putchar_fd(" ", 0);
		count--;
	}
}