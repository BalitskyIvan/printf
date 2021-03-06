/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_min_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:02:02 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 15:02:04 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	skip_todigit(char *format, int i, t_flags *flag)
{
	flag->min_value = 0;
	while (!is_right_arg(format[i]) && format[i] && !ft_isdigit(format[i])
			&& format[i] != '*')
		i++;
	return (i);
}

static int	write_star(t_flags *flag, int res, va_list ap, int i)
{
	res = va_arg(ap, int);
	if (res < 0)
		res = -1;
	flag->min_value = res;
	i++;
	return (i);
}

static int	write_res(t_flags *flag, int flag_to_del, int res, int i)
{
	if (flag_to_del)
	{
		res /= 10;
		flag->min_value = res;
	}
	return (i);
}

static int	create_res(int res, char c)
{
	res += c;
	res *= 10;
	return (res);
}

int			set_max_arg_size(t_flags *flag, va_list ap, char *format, int i)
{
	int	res;
	int	flag_to_del;

	if (format[i] == '.')
	{
		res = 0;
		flag_to_del = 0;
		i = skip_todigit(format, i, flag);
		if (format[i] == '*')
			return (write_star(flag, res, ap, i));
		while (format[i] == '0')
			i++;
		while (ft_isdigit(format[i]) && format[i])
		{
			flag_to_del = 1;
			res = create_res(res, format[i] - '0');
			i++;
		}
		return (write_res(flag, flag_to_del, res, i));
	}
	return (i);
}
