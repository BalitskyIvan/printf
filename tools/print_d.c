#include "../includes/printf.h"

void	print_digit(int d, Flag flag)
{
	if (flag.isPrintLeft)
	{
		if (flag.isPrintNull)
			print_zero(d, flag.minValue);
		ft_putnbr_fd(d, 0);
		print_whitespaces(flag.minField, int_size(d));
	}
	else
	{
		print_whitespaces(flag.minField, int_size(d));
		if (flag.isPrintNull)
			print_zero(d, flag.minValue);
		ft_putnbr_fd(d, 0);
	}
	
}