#include "../includes/printf.h"

static void	print_u(unsigned int u)
{
	if (u >= 10)
	{
		print_u(u / 10);
		print_u(u % 10);
	}
	else
		ft_putchar_fd(u + '0', 0);
	
}

int			print_unsigned_dec(unsigned int u, Flag flag)
{
	unsigned int	res;
	int				min_val;
	int				i;
	
	i = 0;
	res = 4294967295 + 1 + u;
	if (u_int_size(res) < flag.minValue)
		min_val = flag.minValue;
	else
		min_val = u_int_size(res);
	if (flag.isPrintLeft)
	{
		if (flag.minValue > u_int_size(res))
			i += print_zero(u_int_size(u), flag.minValue);
		else if (flag.minField > u_int_size(u) && flag.isPrintNull)
			i += print_zero(u_int_size(u), flag.minValue);
		print_u(u);
		if(!flag.isPrintNull)
			i += print_whitespaces(flag.minField, min_val);
	}
	else
	{
		if(!flag.isPrintNull)
			i += print_whitespaces(flag.minField, min_val);
		if (flag.minValue > u_int_size(res))
			i += print_zero(u_int_size(u), flag.minValue);
		else if (flag.minField > u_int_size(u) && flag.isPrintNull)
			i += print_zero(u_int_size(u), flag.minValue);
		print_u(u);
	}
	i += u_int_size(u);
	return (i);
}