#include "../includes/printf.h"

void	print_p(unsigned long long p, Flag flag)
{
	char	*hex;
	char	*res;
	int		count;
	int		val_copy;

	count = 0;
	val_copy = val;
	if (is_upper)
		hex = "0123456789abcdf";
	else
		hex = "0123456789ABCDF";
	while (val > 0)
	{
		val_copy /= 16;
		count++;
	}
	res = malloc(count);
	while (val > 0)
	{
		res[count] = hex[val % 16];
		val /= 16;
	}
	return (res);
}