#include "../includes/printf.h"

int		is_right_arg(char c)
{
	if (c == 'c' ||
		c == 's' ||
		c == 'p' ||
		c == 'd' ||
		c == 'i' ||
		c == 'u' ||
		c == 'x' ||
		c == 'X' ||
		c == '%')
		return (1);
	else
		return (0);
}

int	set_left_or_zero(Flag *flag, char *format, int i)
{
	int i2;

	i2 = i;
	while (!ft_isdigit(format[i]) && !is_right_arg(format[i])
			&& format[i] != '-')
	{
		if (format[i] == '-')
		{
			flag->isPrintLeft = 1;
			return (i);
		}
		i++;
	}
}

int	set_min_field_size(Flag *flag, char *format, int i)
{
	int res;
	int flag_to_del;

	res = 0;
	flag_to_del = 0;
	while(ft_isdigit(format[i]))
	{
		flag_to_del = 1;
		res += format[i] - '0';
		res *= 10;
		i++;
	}
	if (flag_to_del)
		res /= 10;
	else
		res = -1;
	flag->minField = res;
	return (i);
}

int	set_max_arg_size(Flag *flag, char *format, int i)
{
	int	res;
	int	flag_to_del;

	res = 0;
	flag_to_del = 0;
	while(ft_isdigit(format[i]))
	{
		flag_to_del = 1;
		res += format[i] - '0';
		res *= 10;
		i++;
	}
	if (flag_to_del)
		res /= 10;
	else
		res = -1;
	flag->minValue = res;
	return (i);
}