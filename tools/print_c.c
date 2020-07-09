#include "../includes/printf.h"

int	print_char(char c, Flag flag)
{
	int i;
	
	i = 1;
	if (flag.isPrintLeft)
	{
		ft_putchar_fd(c, 1);
		i += print_whitespaces(flag.minField, 1);
	}
	else
	{
		i += print_whitespaces(flag.minField, 1);
		ft_putchar_fd(c, 1);
	}
	return (i);
}