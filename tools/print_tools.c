#include "../includes/printf.h"

int		int_size(long long d)
{
	int i;

	i = 0;
	if (d < 0)
	{
		i++;
		d *= -1;
	}
	if (d == 0)
		i++;
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
	if (u == 0)
		i++;
	while (u > 0)
	{
		u /= 10;
		i++;
	}
	return (i);
}

int		print_whitespaces(int count, int arg_size)
{
	int i;
	
	i = 0;
	count -= arg_size;
	while (count > 0)
	{
		i++;
		ft_putchar_fd(' ', 1);
		count--;
	}
	return (i);
}

int		print_zero(int size, int min_arg_size)
{
	int i;
	
	i = 0;
	while (min_arg_size > size)
	{
		i++;
		ft_putchar_fd('0', 1);
		min_arg_size--;
	}
	return (i);
}

int		get_string_size(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}