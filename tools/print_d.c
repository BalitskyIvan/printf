#include "../includes/printf.h"

int	print_digit(int d, Flag flag)
{
	int min_val;
	int i;
	
	i = 0;
	if (int_size(d) < flag.minValue)
		min_val = flag.minValue;
	else
		min_val = int_size(d);
	if (flag.isPrintLeft)
	{
		if (d < 0)
		{
			ft_putchar_fd('-', 1);
			i++;
		}
		if (flag.minValue > int_size(d))
			i += print_zero(int_size(d), flag.minValue);
		else if (flag.minField + 1 > int_size(d) && flag.isPrintNull)
			i += print_zero(int_size(d), flag.minField + 1);
		ft_putnbr_fd(d, 1);
		if (!flag.isPrintNull)
			i += print_whitespaces(flag.minField, min_val);
	}
	else
	{
		if (!flag.isPrintNull)
			i += print_whitespaces(flag.minField, min_val);
		if (d < 0)
		{
			ft_putchar_fd('-', 1);
			i++;
		}
		if (flag.minValue + 1 > int_size(d))
			i += print_zero(int_size(d), flag.minValue + 1);
		else if (flag.minField > int_size(d) && flag.isPrintNull)
			i += print_zero(int_size(d), flag.minField);
		ft_putnbr_fd(d, 1);
	}
	i += int_size(d);
	return (i);
}