#include "../includes/printf.h"

void	print_hex(char *hex)
{
	int i;
	
	i = 0;
	while(hex[i])
	{
		ft_putchar_fd(hex[i], 1);
		i++;
	}
}

char *convert_hex(int is_upper, int val)
{
	char	*hex;
	char	*res;
	int		count;
	int		val_copy;

	count = 0;
	val_copy = val;
	if (is_upper)
		hex = "0123456789abcdf";
	else
		hex = "0123456789ABCDF";
	while (val > 0)
	{
		val_copy /= 16;
		count++;
	}
	res = malloc(count);
	while (val > 0)
	{
		res[count] = hex[val % 16];
		val /= 16;
	}
	return (res);
}

int print_x(unsigned int x, Flag flag)
{
	char *res;
	int		is_upper;
	
	
	is_upper = 0;
	if (flag.argType == 'X')
		is_upper = 1;
	res = convert_hex(is_upper, x);
	if (flag.isPrintLeft)
	{
		if (x < 0)
			ft_putchar_fd('-', 0);
		if (flag.isPrintNull)
			print_zero(get_string_size(res), flag.minValue);
		print_hex(res);
		print_whitespaces(flag.minField, get_string_size(res));
	}
	else
	{
		print_whitespaces(flag.minField, get_string_size(res));
		if (x < 0)
			ft_putchar_fd('-', 0);
		if (flag.isPrintNull)
		{
			print_zero(get_string_size(res), flag.minValue);
		}
		print_hex(res);
	}
	return (0);
}
