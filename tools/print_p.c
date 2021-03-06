/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:51:44 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 15:51:46 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	print_hex(char *hex)
{
	int i;

	i = 0;
	if (!hex[i])
		ft_putchar_fd('0', 1);
	while (hex[i])
	{
		ft_putchar_fd(hex[i], 1);
		i++;
	}
}

static char	*convert_p(unsigned long long val)
{
	char				*hex;
	char				*res;
	int					count;
	unsigned long long	val_copy;

	count = 0;
	val_copy = val;
	hex = "0123456789abcdef";
	while (val_copy > 0)
	{
		val_copy /= 16;
		count++;
	}
	if (!(res = malloc(count + 1)))
		return ("n");
	res[count] = '\0';
	while (val > 0)
	{
		res[count - 1] = hex[val % 16];
		val /= 16;
		count--;
	}
	return (res);
}

static int	print_left(t_flags flag, int min_val, int i, char *res)
{
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	if (flag.min_value > get_string_size(res))
		i += print_zero(get_string_size(res), flag.min_value);
	else if (flag.min_field > get_string_size(res) && flag.is_print_null)
		i += print_zero(get_string_size(res), flag.min_field);
	if (((flag.min_value != 0 && get_string_size(res)) || flag.min_value == -1)
		|| (flag.min_value == 0 && get_string_size(res) > 0))
		print_hex(res);
	if ((!flag.is_print_null && flag.min_value != 0)
		|| (flag.min_value == 0 && get_string_size(res) > 0))
		i += print_whitespaces(flag.min_field, min_val + 2);
	if (!flag.is_print_null && flag.min_value == 0 && get_string_size(res) <= 0)
		i += print_whitespaces(flag.min_field, min_val + 1);
	return (i);
}

static int	print_right(t_flags flag, int min_val, int i, char *res)
{
	if ((!flag.is_print_null && flag.min_value != 0)
		|| (flag.min_value == 0 && get_string_size(res) > 0))
		i += print_whitespaces(flag.min_field, min_val + 2);
	if (!flag.is_print_null && flag.min_value == 0 && get_string_size(res) <= 0)
		i += print_whitespaces(flag.min_field, min_val + 1);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	if (flag.min_value > get_string_size(res))
		i += print_zero(get_string_size(res), flag.min_value);
	else if (flag.min_field > get_string_size(res) && flag.is_print_null)
		i += print_zero(get_string_size(res), flag.min_field);
	if (((flag.min_value != 0 && get_string_size(res)) || flag.min_value == -1)
		|| (flag.min_value == 0 && get_string_size(res) > 0))
		print_hex(res);
	return (i);
}

int			print_p(unsigned long long p, t_flags flag)
{
	char	*res;
	int		min_val;
	int		i;

	i = 2;
	res = convert_p(p);
	if (res[0] == 'n')
		return (-1);
	if (get_string_size(res) < flag.min_value)
		min_val = flag.min_value;
	else
	{
		min_val = get_string_size(res);
		if (min_val == 0)
			min_val = 1;
	}
	if (flag.is_print_left)
		i = print_left(flag, min_val, i, res);
	else
		i = print_right(flag, min_val, i, res);
	if (p == 0 && flag.min_value != 0 && flag.min_value <= get_string_size(res))
		i++;
	i += get_string_size(res);
	free(res);
	return (i);
}
