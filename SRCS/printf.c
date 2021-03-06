/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:54:45 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 12:54:58 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	print(char *format, va_list ap)
{
	t_flags		flag;
	t_counter	counter;

	counter.iterator = 0;
	counter.size = 0;
	while (format[counter.iterator])
	{
		if (format[counter.iterator] == '%')
		{
			flag = parse_flags(format, ap, counter.iterator);
			counter = print_arg(flag, ap, format, counter);
			if (counter.size == -1)
				return (-1);
		}
		else
		{
			ft_putchar_fd(format[counter.iterator], 1);
			counter.iterator++;
			counter.size++;
		}
	}
	return (counter.size);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		arg_count;

	va_start(ap, format);
	arg_count = print(format, ap);
	va_end(ap);
	write(0, "\0", 1);
	return (arg_count);
}
