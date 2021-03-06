/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:58:15 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 12:58:20 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static	void	print_sym(char *format, t_counter *counter)
{
	while (format[counter->iterator] != '%' &&
		format[counter->iterator] != '\0')
	{
		if (format[counter->iterator] != ' ')
			ft_putchar_fd(format[counter->iterator], 1);
		counter->iterator++;
		counter->size++;
	}
}

static	int		pass_arg(char *format, int i)
{
	while (is_right_arg(format[i]) != 1 &&
			format[i] != '\0')
		i++;
	if (format[i] != '\0')
		i++;
	return (i);
}

static	int		print(t_flags flag, va_list ap)
{
	int size;

	if (flag.arg_type == 'c')
		size = print_char(va_arg(ap, int), flag);
	if (flag.arg_type == 's')
		size = print_string(va_arg(ap, char *), flag);
	if (flag.arg_type == '%')
		size = print_percent(flag);
	if (flag.arg_type == 'd' || flag.arg_type == 'i')
		size = print_digit(va_arg(ap, int), flag);
	if (flag.arg_type == 'u')
		size = print_unsigned_dec(va_arg(ap, unsigned int), flag);
	if (flag.arg_type == 'p')
		size = print_p(va_arg(ap, unsigned long long), flag);
	if (flag.arg_type == 'x' || flag.arg_type == 'X')
		size = print_x(va_arg(ap, unsigned int), flag);
	return (size);
}

t_counter		print_arg(t_flags flag, va_list ap,
char *format, t_counter counter)
{
	int	size;

	size = 0;
	counter.iterator++;
	if (flag.arg_type == 0)
		print_sym(format, &counter);
	else
	{
		size = print(flag, ap);
		if (size == -1)
			counter.size = -1;
		else
			counter.size += size;
		counter.iterator = pass_arg(format, counter.iterator);
	}
	return (counter);
}
