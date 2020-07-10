#include "../includes/printf.h"


Flag		parse_flags(char *format, va_list ap, int i)
{
	Flag	flag;
	int		minF;

	i++;
	flag.isPrintLeft = 0;
	flag.isPrintNull = 0;
	flag.minField = -1;
	set_left_or_zero(&flag, format, i);
	while (!is_right_arg(format[i]) && format[i])
	{
		set_min_field_size(&flag, ap, format, i);
		set_max_arg_size(&flag, ap, format, i);
	}
	set_arg(&flag, format, i);
	return flag;
}