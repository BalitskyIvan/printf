#include "../includes/printf.h"

void	print_digit(int d, Flag flag)
{
	if (flag.isPrintLeft)
	{
		if (d < 0)
			ft_putchar_fd('-', 0);
		if (flag.isPrintNull)
			print_zero(int_size(d), flag.minValue);
		ft_putnbr_fd(d, 0);
		print_whitespaces(flag.minField, int_size(d));
	}
	else
	{
		print_whitespaces(flag.minField, int_size(d));
		if (d < 0)
			ft_putchar_fd('-', 0);
		if (flag.isPrintNull)
		{
			print_zero(int_size(d), flag.minValue);
		}
		ft_putnbr_fd(d, 0);
	}
}