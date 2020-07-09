#include "../includes/printf.h"

int		sizeof_double(double d)
{
	int i = 0;
	unsigned long long res;
	
	res = d;
	while (res > 0)
	{
		i++;
		res /= 10;
	}
	return(i);
}

unsigned long long	get_whole(double d)
{
	unsigned long long res;

	if (d < 0)
	{
		res = d;
		res *= -1;
	}
	else
		res = d;
	return (res);
}

int get_fract(double f, unsigned long long whole, int after_dot)
{
	double	doub;
	double	d2;
	int		res;
	int		size;
	int		i;

	size = 6;
	i = 1;
	res = 0;
	if (f < 0)
		f *= -1;
	doub = f - whole;
	d2 = doub;
	if (after_dot != -1 && after_dot != size)
		size = after_dot;
	while (size >= 0 && d2 - res > 0)
	{
		printf("dob %f", d2);
		printf("RES %d", res);
		res = doub * i;
		i *= 10;
		d2 *= 10;
		size--;
	}
	if ((doub - res) * 10 > 5)
		res += 1;
	return (res);
}

char *convert(unsigned long long val, int size)
{
	char	*res;

	res = malloc(size + 1);
	res[size] = '\0';
	size--;
	while (val > 0)
	{
		res[size] = (val % 10) + '0';
		size--;
		val /= 10;
	}
	return (res);
}

FloatConverter	convert_to_char(double f, int after_dot)
{
	unsigned long long	whole;
	int					fractional;
	FloatConverter		flc;
	int					after_size;
	
	if (f < 0)
		flc.is_minus = 1;
	whole = get_whole(f);
	fractional = get_fract(f, whole, after_dot);
	after_size = int_size(fractional) - 1;
	flc.str1 = convert(whole, sizeof_double(f));
	flc.str2 = convert(fractional, after_size);
	return (flc);
}
