#include "../includes/printf.h"

static void	print_u(unsigned int u)
{
	if (u >= 10)
	{
		print_u(u / 10);
		print_u(u % 10);
	}
	else
		ft_putchar_fd(u + '0', 1);
	
}

int			print_unsigned_dec(unsigned int u, Flag flag)
{
	unsigned int	res;
	int				min_val;
	int				i;
	
	i = 0;
	res = 4294967295 + 1 + u;
	if (flag.minValue > 0 && u_int_size(res) < flag.minValue)
		min_val = flag.minValue;
	else
		min_val = u_int_size(res) - 1;
	if (flag.isPrintLeft)
	{
		if (flag.minValue + 1 > u_int_size(res))
			i += print_zero(u_int_size(u), flag.minValue + 1);
		else if (flag.minField + 1 > u_int_size(u) && flag.isPrintNull)
			i += print_zero(u_int_size(u), flag.minValue + 1);
		print_u(u);
		i += print_whitespaces(flag.minField, min_val);
	}
	else
	{
		i += print_whitespaces(flag.minField, min_val);
		if (flag.minValue + 1 > u_int_size(res))
			i += print_zero(u_int_size(u), flag.minValue + 1);
		else if (flag.minField + 1 > u_int_size(u) && flag.isPrintNull)
			i += print_zero(u_int_size(u), flag.minValue + 1);
		print_u(u);
	}
	i += u_int_size(u);
	return (i);
}