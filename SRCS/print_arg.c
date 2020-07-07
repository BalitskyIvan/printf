#include "../includes/printf.h"

int	print_sym(char *format, int i)
{
	while (format[i] != '%' && format[i] != '\0')
	{
		ft_putchar_fd(format[i], 0);
		i++;
	}
	return (i);
}

int	pass_arg(char *format, int i)
{
	while (is_right_arg(format[i]) != 1 && 
			format[i] != '\0')
		i++;
	if (format[i] != '\0')
		i++;
	return (i);
}

int	print_arg(Flag flag, va_list ap, char *format, int i)
{
	i++;
	if (flag.argType == 0)
		i = print_sym(format, i);
	else
	{
		if (flag.argType == 'c')
			print_char(va_arg(ap, int), flag);
		if (flag.argType == 's')
			print_string(va_arg(ap, char *), flag);
		if (flag.argType == '%')
			print_percent(flag);
		if (flag.argType == 'd' || flag.argType == 'i')
			print_digit(va_arg(ap, int), flag);
		if (flag.argType == 'u')
			print_digit(va_arg(ap, unsigned int), flag);
		//if (flag.argType == "x" || flag.argType == "X")
		i = pass_arg(format, i);
	}
	return (i);
}