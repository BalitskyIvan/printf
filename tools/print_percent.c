#include "../includes/printf.h"

void	print_percent(Flag flag)
{
	if (flag.isPrintLeft)
	{
		ft_putchar_fd('%', 0);
		print_whitespaces(flag.minField, 1);
	}
	else
	{
		print_whitespaces(flag.minField, 1);
		ft_putchar_fd('%', 0);
	}
}