#include "../includes/printf.h"

void	print_sym(char *format, Counter *counter)
{
	while (format[counter->iterator] != '%' && format[counter->iterator] != '\0')
	{
		if (format[counter->iterator] != ' ')
			ft_putchar_fd(format[counter->iterator], 1);
		counter->iterator++;
		counter->size++;
	}
}

int		pass_arg(char *format, int i)
{
	while (is_right_arg(format[i]) != 1 && 
			format[i] != '\0')
		i++;
	if (format[i] != '\0')
		i++;
	return (i);
}

Counter		print_arg(Flag flag, va_list ap, char *format, Counter counter)
{
	counter.iterator++;
	if (flag.argType == 0)
		print_sym(format, &counter);
	else
	{
		if (flag.argType == 'c')
			counter.size += print_char(va_arg(ap, int), flag);
		if (flag.argType == 's')
			counter.size += print_string(va_arg(ap, char *), flag);
		if (flag.argType == '%')
			counter.size += print_percent(flag);
		if (flag.argType == 'd' || flag.argType == 'i')
			counter.size += print_digit(va_arg(ap, int), flag);
		if (flag.argType == 'u')
			counter.size += print_unsigned_dec(va_arg(ap, unsigned int), flag);
		if (flag.argType == 'p')
			counter.size += print_p(va_arg(ap, unsigned long long), flag);
		if (flag.argType == 'x' || flag.argType == 'X')
			counter.size += print_x(va_arg(ap, unsigned int), flag);
		counter.iterator = pass_arg(format, counter.iterator);
	}
	return (counter);
}