#include "../includes/printf.h"

int		int_size(int d)
{
	int i;

	i = 1;
	if (d == -2147483648)
		return (10);
	else if (d < 0)
		d *= -1;
	while (d > 0)
	{
		d /= 10;
		i++;
	}
	return (i);
}

int		u_int_size(unsigned int u)
{
	int i;

	i = 1;
	while (u > 0)
	{
		u /= 10;
		i++;
	}
	return (i);
}

void	print_whitespaces(int count, int arg_size)
{
	count -= arg_size;
	while (count > 0)
	{
		ft_putchar_fd(' ', 0);
		count--;
	}
}

void	print_zero(int size, int min_arg_size)
{
	while (min_arg_size > size)
	{
		ft_putchar_fd('0', 0);
		min_arg_size--;
	}
}

int		get_string_size(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}