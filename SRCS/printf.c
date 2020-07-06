#include "../includes/printf.h"



int print(char *format, va_list ap)
{
	int i;
	Flag flag;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			flag = parse_flags(format, i);
			i = print_arg(flag, ap, format, i);
		}
		else
		{
			ft_putchar_fd(format[i], 0);
			i++;
		}
	}
	write(0, 0, 1);
	return (i);
}

int ft_printf(char *format, ...)
{
	va_list ap;
	int		arg_count;

	va_start(ap, format);
	arg_count = print(format, ap);
	va_end(ap);
	return(arg_count);
}