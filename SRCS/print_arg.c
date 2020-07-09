#include "../includes/printf.h"

void	print_sym(char *format, Counter *counter)
{
	while (format[counter->iterator] != '%' && format[counter->iterator] != '\0')
	{
		ft_putchar_fd(format[counter->iterator], 0);
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
		if (flag.argType == 'f')
			counter.size += print_f(va_arg(ap, double), flag);
		if (flag.argType == 'e')
			counter.size += print_e(va_arg(ap, double), flag);
		if (flag.argType == 'g')
			counter.size += print_g(va_arg(ap, double), flag);
		if (flag.argType == 'n')
			*va_arg(ap, int*) = counter.size;
		counter.iterator = pass_arg(format, counter.iterator);
	}
	return (counter);
}