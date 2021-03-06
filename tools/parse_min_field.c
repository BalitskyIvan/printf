/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_wtool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:40:36 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 13:40:38 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	skip_todigit(char *format, int i)
{
	while (!is_right_arg(format[i]) && format[i] != '.' && format[i] != '*' &&
			(!ft_isdigit(format[i]) || format[i] == '0') && format[i])
		i++;
	return (i);
}

static int	check_star(t_flags *flag, va_list ap, int i)
{
	int res;

	res = 0;
	res = va_arg(ap, int);
	if (res < 0)
	{
		flag->is_print_left = 1;
		flag->is_print_null = 0;
		res *= -1;
	}
	flag->min_field = res;
	i++;
	return (i);
}

static int	write_res(int res, t_flags *flag, int i)
{
	res /= 10;
	flag->min_field = res;
	return (i);
}

int			set_min_field_size(t_flags *flag, va_list ap, char *format, int i)
{
	int res;
	int flag_to_del;

	res = 0;
	flag_to_del = 0;
	i = skip_todigit(format, i);
	while (!is_right_arg(format[i]) && format[i] != '.' && format[i])
	{
		while (ft_isdigit(format[i]) && format[i])
		{
			flag_to_del = 1;
			res += format[i] - '0';
			if (res != 0)
				res *= 10;
			i++;
		}
		if (flag_to_del)
			return (write_res(res, flag, i));
		flag_to_del = 0;
		if (format[i] == '*')
			return (check_star(flag, ap, i));
		i++;
	}
	return (i);
}
