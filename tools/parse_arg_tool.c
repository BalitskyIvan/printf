/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:40:10 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 13:40:13 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		is_right_arg(char c)
{
	if (c == 'c' ||
		c == 's' ||
		c == 'p' ||
		c == 'd' ||
		c == 'i' ||
		c == 'u' ||
		c == 'x' ||
		c == 'X' ||
		c == '%')
		return (1);
	else
		return (0);
}

int		is_print_left(char *format, int i)
{
	while (!is_right_arg(format[i]) && format[i])
	{
		if (format[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void	set_left_or_zero(t_flags *flag, char *format, int i)
{
	int	left_sat;

	if ((left_sat = is_print_left(format, i)))
		flag->is_print_left = 1;
	while (!left_sat && !is_right_arg(format[i]) && format[i]
			&& (!ft_isdigit(format[i]) || format[i] == '0'))
	{
		if (format[i] == '0')
		{
			flag->is_print_null = 1;
			flag->is_print_left = 0;
		}
		i++;
	}
}

void	set_arg(t_flags *flag, char *format, int i)
{
	while (!is_right_arg(format[i]) && format[i])
		i++;
	if (is_right_arg(format[i]))
		flag->arg_type = format[i];
	else
		flag->arg_type = 0;
}
