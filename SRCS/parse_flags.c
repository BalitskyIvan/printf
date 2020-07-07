#include "../includes/printf.h"

Flag	parse_flags(char *format, int i)
{
	Flag	flag;

	i++;
	set_left_or_zero(&flag, format, i);
	set_min_field_size(&flag, format, i);
	set_max_arg_size(&flag, format, i);
	set_arg(&flag, format, i);
	return flag;
}