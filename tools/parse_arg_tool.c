#include "../includes/printf.h"

void	set_zero(Flag *flag, char c)
{
	if (c == '0')
		flag->isPrintNull = 1;
	else
		flag->isPrintNull = 0;
}

void	set_left(Flag *flag, char c)
{
	if (c == '-')
		flag->isPrintLeft = 1;
	else
		flag->isPrintLeft = 0;
}

void	set_screen(Flag *flag, char c)
{
	if (c == '%')
		flag->isPrintScreen = 1;
	else
		flag->isPrintScreen = 0;
}

int		set_min_field_size(Flag *flag, char *format, int i)
{
	int res;

	res = -1;
	while(ft_isdigit(format[i]))
	{
		res += format[i] - '0';
		res *= 10;
		i++;
	}
	if (res > -1)
		res /= 10;
	flag->minField = res;
	return (i);
}

int		set_max_arg_size(Flag *flag, char *format, int i)
{
	
	int res;

	res = -1;
	while(ft_isdigit(format[i]))
	{
		res += format[i] - '0';
		res *= 10;
		i++;
	}
	if (res > -1)
		res /= 10;
	flag->minValue = res;
	return (i);
}