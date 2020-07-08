#include "../includes/printf.h"

static void	print_hex(char *hex)
{
	int i;
	
	i = 0;
	while(hex[i])
	{
		ft_putchar_fd(hex[i], 1);
		i++;
	}
}

static char *convert_hex(unsigned long long val)
{
	char	*hex;
	char	*res;
	int		count;
	unsigned long long	val_copy;

	count = 0;
	val_copy = val;
	hex = "0123456789abcdef";
	while (val_copy > 0)
	{
		val_copy /= 16;
		count++;
	}
	res = malloc(count + 1);
	res[count] = '\0';
	while (val > 0)
	{
		res[count - 1] = hex[val % 16];
		val /= 16;
		count--;
	}
	return (res);
}

int print_p(unsigned long long p, Flag flag)
{
	char	*res;
	int		min_val;
	int		i;

	i = 2;
	res = convert_hex(p);
	if (get_string_size(res) < flag.minValue)
		min_val = flag.minValue;
	else
		min_val = get_string_size(res);
	if (flag.isPrintLeft)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
		if (flag.minValue > get_string_size(res))
			i += print_zero(get_string_size(res), flag.minValue);
		else if (flag.minField > get_string_size(res) && flag.isPrintNull)
			i += print_zero(get_string_size(res), flag.minField);
		print_hex(res);
		if (!flag.isPrintNull)
			i += print_whitespaces(flag.minField, min_val + 2);
	}
	else
	{
		if (!flag.isPrintNull)
			i += print_whitespaces(flag.minField, min_val + 2);
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
		if (flag.minValue > get_string_size(res))
			i += print_zero(get_string_size(res), flag.minValue);
		else if (flag.minField > get_string_size(res) && flag.isPrintNull)
			i += print_zero(get_string_size(res), flag.minField);
		print_hex(res);
	}
	i += get_string_size(res);
	free(res);
	return (i);
}
