#include "../includes/printf.h"

int	print_percent(Flag flag)
{
	int i;
	
	i = 1;
	if (flag.isPrintLeft)
	{
		ft_putchar_fd('%', 1);
		i += print_whitespaces(flag.minField, 1);
	}
	else
	{
		if (!flag.isPrintNull)
			i += print_whitespaces(flag.minField, 1);
		else
			i += print_zero(1, flag.minField);
		ft_putchar_fd('%', 1);
	}
	return (i);
}
