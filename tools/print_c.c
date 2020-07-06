#include "../includes/printf.h"

void	print_char(char c, Flag flag)
{
	if (flag.isPrintLeft)
	{
		if (flag.minValue != 0)
			ft_putchar_fd(c, 0);
		print_whitespaces(flag.minField, 1);
	}
	else
	{
		print_whitespaces(flag.minField, 1);
		if (flag.minValue != 0)
			ft_putchar_fd(c, 0);
	}
}