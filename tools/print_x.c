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

static char *convert_hex(int is_upper, unsigned int val)
{
	char			*res;
	char			*hex;
	int				count;
	unsigned int	val_copy;

	count = 0;
	val_copy = val;
	if (!is_upper)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
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

int print_x(unsigned int x, Flag flag)
{
	char	*res;
	int		is_upper;
	int		min_val;
	int		i;
	
	i = 0;
	is_upper = 0;
	if (flag.argType == 'X')
		is_upper = 1;
	res = convert_hex(is_upper, x);
	if (get_string_size(res) < flag.minValue)
		min_val = flag.minValue;
	else
		min_val = get_string_size(res);
	if (flag.isPrintLeft)
	{
		if (x < 0)
		{
			ft_putchar_fd('-', 1);
			i++;
		}
		if (flag.minValue > get_string_size(res))
			i += print_zero(get_string_size(res), flag.minValue);
		else if (flag.minField > get_string_size(res) && flag.isPrintNull)
			i += print_zero(get_string_size(res), flag.minField);
		print_hex(res);
		i += print_whitespaces(flag.minField, min_val);
	}
	else
	{
		i += print_whitespaces(flag.minField, min_val);
		if (x < 0)
		{
			ft_putchar_fd('-', 1);
			i++;
		}
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
