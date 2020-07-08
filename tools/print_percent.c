#include "../includes/printf.h"

int	print_percent(Flag flag)
{
	int i;
	
	i = 1;
	if (flag.isPrintLeft)
	{
		ft_putchar_fd('%', 0);
		i += print_whitespaces(flag.minField, 1);
	}
	else
	{
		i += print_whitespaces(flag.minField, 1);
		ft_putchar_fd('%', 0);
	}
	return (i);
}