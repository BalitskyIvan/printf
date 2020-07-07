#include "../includes/printf.h"

Flag	parse_flags(char *format, int i)
{
	Flag	flag;

	i++;
	i = set_left_or_zero(&flag, format, i);
	i = set_min_field_size(&flag, format, i);
	if (format[i] == '.')
		i++;
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