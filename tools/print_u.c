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

void		print_unsigned_dec(unsigned int u, Flag flag)
{
	unsigned int res;
	
	res = 4294967295 + 1 + u;
	if (flag.isPrintLeft)
	{
		if (flag.isPrintNull)
			print_zero(u_int_size(u), flag.minValue);
		print_u(u);
		print_whitespaces(flag.minField, u_int_size(u));
	}
	else
	{
		print_whitespaces(flag.minField, u_int_size(u));
		if (flag.isPrintNull)
			print_zero(u_int_size(u), flag.minValue);
		print_u(u);
	}
}