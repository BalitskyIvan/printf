/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:52:48 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 15:52:49 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	print_u(unsigned int u)
{
	if (u >= 10)
	{
		print_u(u / 10);
		print_u(u % 10);
	}
	else
		ft_putchar_fd(u + '0', 1);
}

static int	print_left(t_flags flag, int i, int min_val, unsigned int u)
{
	if (flag.is_print_null)
		i += print_zero(u_int_size(u) - 1, flag.min_field);
	if (min_val != 0 || (min_val == 0 && u != 0))
		print_u(u);
	else
		i--;
	if (!flag.is_print_null)
		i += print_whitespaces(flag.min_field, flag.min_value);
	return (i);
}

static int	print_right(t_flags flag, int i, int min_val, unsigned int u)
{
	if (flag.is_print_null)
		i += print_zero(u_int_size(u) - 1, flag.min_field);
	if (min_val != 0 || (min_val == 0 && u != 0))
		print_u(u);
	else
		i--;
	return (i);
}

static int	get_minval(t_flags flag, unsigned int u)
{
	if (u_int_size(u) > flag.min_value && (flag.min_value != 0 ||
		(flag.min_value == 0 && u != 0)))
		return (u_int_size(u) - 1);
	return (flag.min_value);
}

int			print_unsigned_dec(unsigned int u, t_flags flag)
{
	unsigned int	res;
	int				min_val;
	int				i;

	i = 0;
	res = 4294967295 + 1 + u;
	min_val = flag.min_value;
	flag.min_value = get_minval(flag, u);
	if (min_val != -1)
		flag.is_print_null = 0;
	if (flag.is_print_left)
	{
		if (min_val > u_int_size(res) - 1)
			i += print_zero(u_int_size(u) - 1, flag.min_value);
		i = print_left(flag, i, min_val, u);
	}
	else
	{
		if (!flag.is_print_null)
			i += print_whitespaces(flag.min_field, flag.min_value);
		if (min_val > u_int_size(res) - 1)
			i += print_zero(u_int_size(u) - 1, flag.min_value);
		i = print_right(flag, i, min_val, u);
	}
	return (i + u_int_size(u) - 1);
}
