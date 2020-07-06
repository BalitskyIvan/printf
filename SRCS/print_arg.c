#include "../includes/printf.h"

int	print_sym(char *format, int i)
{
	while (format[i] != '%' && format[i] != '\0')
	{
		ft_putchar_fd(format[i], 0);
		i++;
	}
}

int	print_arg(Flag flag, va_list ap, char *format, int i)
{
	if (flag.isPrintScreen)
		ft_putchar_fd("%%", 0);
	if (flag.argType == 0)
		i = print_sym(format, i);
	else
	{
		if (flag.argType == "c")
			
		if (flag.argType == "s")
		if (flag.argType == "p")
		if (flag.argType == "d")
		if (flag.argType == "i")
		if (flag.argType == "u")
		if (flag.argType == "x" || flag.argType == "X")

	}
	
	return (i);
}