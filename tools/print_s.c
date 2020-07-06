#include "../includes/printf.h"


void	put_string(char *s, int max_size)
{
	int i;

	i = 0;
	while (s[i] && i < max_size)
	{
		ft_putchar_fd(s[i], 0);
		i++;
	}
}

void	print_string(char *s, Flag flag)
{
	if (flag.isPrintLeft)
	{
		put_string(s, flag.minValue);
		print_whitespaces(flag.minField, get_string_size(s));
	}
	else
	{
		print_whitespaces(flag.minField, get_string_size(s));
		put_string(s, flag.minValue);
	}
}
