#include "../includes/printf.h"


Flag		parse_flags(char *format, va_list ap, int i)
{
	Flag	flag;
	int		minF;

	i++;
	flag.isPrintLeft = 0;
	flag.isPrintNull = 0;
	set_left_or_zero(&flag, format, i);
	set_min_field_size(&flag, format, i);
	set_max_arg_size(&flag, format, i);
	set_arg(&flag, format, i);
	if (set_width(format, i))
	{
		minF = va_arg(ap, int);
		if (minF < 0)
		{
			flag.isPrintLeft = 1;
			minF *= -1;
		}
		if (flag.minField == -1)
			flag.minField = minF;
	}
	return flag;
}