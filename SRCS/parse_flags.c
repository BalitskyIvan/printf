#include "../includes/printf.h"


Flag		parse_flags(char *format, va_list ap, int i)
{
	Flag	flag;
	int		i2;

	i++;
	i2 = i;
	flag.isPrintLeft = 0;
	flag.isPrintNull = 0;
	flag.minField = -1;
	flag.minValue = -1;
	set_left_or_zero(&flag, format, i2);
	while (!is_right_arg(format[i2]) && format[i2])
	{
		i2 = set_min_field_size(&flag, ap, format, i2);
		i2 = set_max_arg_size(&flag, ap, format, i2);
	}
	set_arg(&flag, format, i);
	return flag;
}