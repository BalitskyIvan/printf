#include "../includes/printf.h"

int	set_zero(Flag *flag, char c)
{
	if (c == '0')
	{
		flag->isPrintNull = 1;
		return (1);
	}
	else
	{
		flag->isPrintNull = 0;
		return (0);
	}
}

int	set_left(Flag *flag, char c)
{
	if (c == '-')
	{
		flag->isPrintLeft = 1;
		return (1);
	}
	else
	{
		flag->isPrintLeft = 0;
		return (0);
	}
}

int	set_screen(Flag *flag, char c)
{
	if (c == '%')
	{
		flag->isPrintScreen = 1;
		return (1);
	}
	else
	{
		flag->isPrintScreen = 0;
		return (0);
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