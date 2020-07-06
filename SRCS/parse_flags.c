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
		c == 'X')
		return (1);
	else
		return (0);
}

Flag	parse_flags(char *format, int i)
{
	Flag	flag;

	i++;
	set_zero(&flag, format[i]);
	set_left(&flag, format[i]);
	set_screen(&flag, format[i]);
	i++;
	i = set_min_field_size(&flag, format, i);
	i = set_max_arg_size(&flag, format, i);
	if (is_right_arg(format[i]))
	{
		flag.argType = format[i];
		i++;
	}
	else
		flag.argType = 0;
	flag.iterator = i;
	return flag;
}