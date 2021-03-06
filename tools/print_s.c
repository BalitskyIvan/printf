/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:52:25 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 15:52:26 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			put_string(char *s, int max_size)
{
	int i;

	i = 0;
	while (s[i] && i < max_size)
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}

static int	get_minval(t_flags flag, char *s)
{
	if (flag.min_value != -1 && flag.min_value < get_string_size(s))
		return (flag.min_value);
	else
		return (get_string_size(s));
}

static int	get_minfield(t_flags flag)
{
	if (flag.min_field != -1)
		return (flag.min_field);
	else
		return (0);
}

static int	print_left(t_flags flag, int i, int min_val, int min_field)
{
	if (flag.is_print_null)
		i += print_zero(min_val, min_field);
	else
		i += print_whitespaces(min_field, min_val);
	return (i);
}

int			print_string(char *s, t_flags flag)
{
	int	min_val;
	int	min_field;
	int i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	min_val = get_minval(flag, s);
	min_field = get_minfield(flag);
	if (flag.min_value != -1)
		flag.is_print_null = 0;
	if (flag.is_print_left)
	{
		i += put_string(s, min_val);
		i = print_left(flag, i, min_val, min_field);
	}
	else
	{
		if (flag.is_print_null)
			i += print_zero(min_val, min_field);
		else
			i += print_whitespaces(min_field, min_val);
		i += put_string(s, min_val);
	}
	return (i);
}
