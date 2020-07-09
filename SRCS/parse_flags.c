#include "../includes/printf.h"

static int	set_width(char *format, int i)
{
	while(!is_right_arg(format[i]) && format[i])
	{
		if (format[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

Flag		parse_flags(char *format, va_list ap, int i)
{
	Flag	flag;

	i++;
	set_left_or_zero(&flag, format, i);
	set_min_field_size(&flag, format, i);
	set_max_arg_size(&flag, format, i);
	set_arg(&flag, format, i);
	if (set_width(format, i) && flag.minField == -1)
		flag.minField = va_arg(ap, int);
	return flag;
}