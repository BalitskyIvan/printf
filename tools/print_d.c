#include "../includes/printf.h"

static void	putnbr(long long n)
{
	if (n < 0)
		n *= -1;
	if (n >= 10)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else
		ft_putchar_fd(n + '0', 1);
}

int	print_digit(long long d, Flag flag)
{
	int i;

	i = 0;
	if (int_size(d) > flag.minValue && flag.minValue != 0)
		flag.minValue = int_size(d);
	flag.minField -= flag.minValue;
	if (flag.isPrintLeft)
	{
		if (d < 0)
			ft_putchar_fd('-', 1);
		if (flag.minValue > int_size(d))
			print_zero(int_size(d), flag.minValue);
		else if (flag.isPrintNull)
			i += print_zero(int_size(d), flag.minField);
		else
		{
			if (flag.minValue != 0)
				putnbr(d);
			i += print_whitespaces(flag.minField, flag.minValue);
			return (i + flag.minValue);
		} 
		if (flag.minValue != 0)
			putnbr(d);
	}
	else
	{
		if (flag.isPrintNull)
			i += print_zero(int_size(d), flag.minField);
		else
			i += print_whitespaces(flag.minField, flag.minValue);
	}
	i += int_size(d);
	return (i);
}