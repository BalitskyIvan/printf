#include "../includes/printf.h"

int		put_str(char *str1, char *str2)
{
	int i;
	int size;
	
	i = 0;
	size = 1;
	while (str1[i])
	{
		ft_putchar_fd(str1[i], 1);
		i++;
	}
	ft_putchar_fd('.', 1);
	size += i;
	i = 0;
	while(str2[i])
	{
		ft_putchar_fd(str2[i], 1);
		i++;
	}
	return (size + i);
}

int print_f(double f, Flag flag)
{
	int i;
	FloatConverter flc;

	flc = convert_to_char(f, flag.minValue);
	i = put_str(flc.str1, flc.str2);
	free(flc.str1);
	free(flc.str2);
	return (i);
}
