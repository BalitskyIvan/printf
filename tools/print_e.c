#include "../includes/printf.h"

void	print_end(int i, char *str1)
{
	while (i <= 6)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putchar_fd('e', 1);
	ft_putchar_fd('+', 1);
	i = get_string_size(str1) - 1;
	ft_putchar_fd(i / 10 + '0', 1);
	ft_putchar_fd(i % 10 + '0', 1);
}
void	print_res(double d,  Flag flag)
{
	FloatConverter	flc;
	int				i1;
	int				i2;
	
	i1 = 1;
	flc = convert_to_char(d, flag.minValue);
	ft_putchar_fd(flc.str1[0], 1);
	ft_putchar_fd('.', 1);
	while (i1 <= 6 && flc.str1[i1])
	{
		if (i1 == 6 && flc.str1[i1 + 1] >= '5')
			ft_putchar_fd(flc.str1[i1] + 1, 1);
		else
			ft_putchar_fd(flc.str1[i1], 1);
		i1++;
	}
	i2 = i1;
	while (i2 <= 6 && flc.str2[i2])
	{
		if (i2 == 6 && flc.str2[i2 + 1] >= '5')
			ft_putchar_fd(flc.str2[i2] + 1, 1);
		else
			ft_putchar_fd(flc.str2[i2], 1);
		i2++;
	}
	print_end(i1, flc.str1);
}

int	print_e(double d, Flag flag)
{
	print_res(d, flag);
	return (12);
}