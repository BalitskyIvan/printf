/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:07:50 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 13:07:53 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flags	parse_flags(char *format, va_list ap, int i)
{
	t_flags	flag;
	int		i2;

	i++;
	i2 = i;
	flag.is_print_left = 0;
	flag.is_print_null = 0;
	flag.min_field = -1;
	flag.min_value = -1;
	set_left_or_zero(&flag, format, i2);
	while (!is_right_arg(format[i2]) && format[i2])
	{
		i2 = set_min_field_size(&flag, ap, format, i2);
		i2 = set_max_arg_size(&flag, ap, format, i2);
	}
	set_arg(&flag, format, i);
	return (flag);
}
