/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:53:04 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 15:53:16 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	print_hex(char *hex)
{
	int i;

	i = 0;
	while (hex[i])
	{
		ft_putchar_fd(hex[i], 1);
		i++;
	}
}

static int	print_left(t_flags flag, int i, int min_val, char *res)
{
	if (min_val > get_string_size(res))
		i += print_zero(get_string_size(res), min_val);
	if (flag.is_print_null)
		i += print_zero(get_string_size(res), flag.min_field);
	if (min_val != 0 || (min_val == 0 && !(res[1] == '\0' && res[0] == '0')))
		print_hex(res);
	else
		i--;
	if (!flag.is_print_null)
		i += print_whitespaces(flag.min_field, flag.min_value);
	return (i);
}

static int	print_right(t_flags flag, int i, int min_val, char *res)
{
	if (flag.is_print_null)
		i += print_zero(get_string_size(res), flag.min_field);
	else
		i += print_whitespaces(flag.min_field, flag.min_value);
	if (flag.min_value > get_string_size(res))
		i += print_zero(get_string_size(res), flag.min_value);
	if (min_val != 0 || (min_val == 0 && !(res[1] == '\0' && res[0] == '0')))
		print_hex(res);
	else
		i--;
	return (i);
}

int			print_x(unsigned int x, t_flags flag)
{
	char	*res;
	int		is_upper;
	int		min_val;
	int		i;

	i = 0;
	is_upper = 0;
	if (flag.arg_type == 'X')
		is_upper = 1;
	res = convert_hex(is_upper, x);
	if (res[0] == 'n')
		return (-1);
	min_val = flag.min_value;
	if (flag.min_value != -1)
		flag.is_print_null = 0;
	if (get_string_size(res) > flag.min_value && (flag.min_value != 0 ||
		(flag.min_value == 0 && x != 0)))
		flag.min_value = get_string_size(res);
	if (flag.is_print_left)
		i = print_left(flag, i, min_val, res);
	else
		i = print_right(flag, i, min_val, res);
	i += get_string_size(res);
	free(res);
	return (i);
}
