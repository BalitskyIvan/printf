#include "../includes/printf.h"


int	put_string(char *s, int max_size)
{
	int i;

	i = 0;
	while (s[i] && i < max_size)
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}

int	print_string(char *s, Flag flag)
{
	int	min_val;
	int	min_field;
	int i;

	i = 0;
	if (flag.minValue != -1)
		min_val = flag.minValue;
	else 
		min_val = get_string_size(s);
	if (flag.minField != -1)
		min_field = flag.minField;
	else 
		min_field = 0;
	if (flag.isPrintLeft)
	{
		i += put_string(s, min_val);
		i += print_whitespaces(min_field, min_val);
	}
	else
	{
		i += print_whitespaces(min_field, min_val);
		i += put_string(s, min_val);
	}
	return (i);
}
