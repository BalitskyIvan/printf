#include "../includes/printf.h"

int	print_g(double d, Flag flag)
{
	FloatConverter flc;
	int i;
	
	i = 0;
	flc = convert_to_char(d, flag.minValue);
	if ((get_string_size(flc.str1) + get_string_size(flc.str2) + 
		flc.is_minus + 1) < 12)
		i += print_f(d, flag);
	else
		i += print_e(d, flag);
	return (i);
}