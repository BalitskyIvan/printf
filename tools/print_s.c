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
	int	min_val;
	int	min_field;
	
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
		put_string(s, min_val);
		print_whitespaces(min_field, min_val);
	}
	else
	{
		print_whitespaces(min_field, min_val);
		put_string(s, min_val);
	}
}
