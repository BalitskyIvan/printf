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

void	set_left_or_zero(Flag *flag, char *format, int i)
{
	int	left_sat;

	left_sat = 0;
	while (!is_right_arg(format[i]) && format[i])
	{
		if (format[i] == '-')
		{
			left_sat = 1;
			flag->isPrintLeft = 1;
			flag->isPrintNull = 0;
		}
		i++;
	}
	if (format[i] == '0' && !left_sat)
	{
		flag->isPrintNull = 1;
		flag->isPrintLeft = 0;
	}
}

void	set_min_field_size(Flag *flag, char *format, int i)
{
	int res;
	int flag_to_del;

	res = 0;
	flag_to_del = 0;
	while ((!ft_isdigit(format[i]) || format[i] == '0') && !is_right_arg(format[i]) && format[i])
		i++;
	while(ft_isdigit(format[i]))
	{
		flag_to_del = 1;
		res += format[i] - '0';
		if (res != 0)
			res *= 10;
		i++;
	}
	if (flag_to_del)
		res /= 10;
	else
		res = -1;
	flag->minField = res;
}

void	set_max_arg_size(Flag *flag, char *format, int i)
{
	int	res;
	int	flag_to_del;

	while (!is_right_arg(format[i]) && format[i])
	{
		if (format[i] == '.')
		{	
			res = 0;
			flag_to_del = 0;
			while(ft_isdigit(format[i]) && format[i])
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
		}
		i++;
	}
}

void	set_arg(Flag *flag, char *format, int i)
{
	while (!is_right_arg(format[i]) && format[i])
		i++;
	if (is_right_arg(format[i]))
		flag->argType = format[i];
	else
		flag->argType = 0;
}