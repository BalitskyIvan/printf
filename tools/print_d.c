/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:51:33 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 15:51:36 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	putnbr(long long n)
{
	if (n < 0)
		n *= -1;
	if (n >= 10)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else
		ft_putchar_fd(n + '0', 1);
}

static int	print_left(t_flags flag, int d, int min_val, int i)
{
	if (d < 0)
		ft_putchar_fd('-', 1);
	if (min_val > int_size(d) - 1 && d < 0)
		i += print_zero(int_size(d) - 1, min_val);
	if (d >= 0 && min_val > int_size(d))
		i += print_zero(int_size(d), min_val);
	if (flag.is_print_null)
		i += print_zero(int_size(d), flag.min_field);
	else
	{
		if (flag.min_value != 0)
			putnbr(d);
		else
			i--;
		if (min_val > int_size(d) - 1 && d < 0)
			i += print_whitespaces(flag.min_field, min_val + 1);
		else
			i += print_whitespaces(flag.min_field, flag.min_value);
		return (i + int_size(d));
	}
	if (flag.min_value != 0 || (flag.min_value == 0 && d != 0))
		putnbr(d);
	else
		i--;
	return (i + int_size(d));
}

static int	print_zeros(int d, int min_val, int i)
{
	if (d < 0)
		ft_putchar_fd('-', 1);
	if (min_val > int_size(d) - 1 && d < 0)
		i += print_zero(int_size(d) - 1, min_val);
	if (d >= 0 && min_val > int_size(d))
		i += print_zero(int_size(d), min_val);
	return (i);
}

static int	print_right(t_flags flag, int d, int min_val, int i)
{
	if (flag.is_print_null)
	{
		if (d < 0)
			ft_putchar_fd('-', 1);
		i += print_zero(int_size(d), flag.min_field);
		if (flag.min_value != 0)
			putnbr(d);
		else
			i--;
		return (i + int_size(d));
	}
	else
	{
		if (min_val > int_size(d) - 1 && d < 0)
			i += print_whitespaces(flag.min_field, min_val + 1);
		else
			i += print_whitespaces(flag.min_field, flag.min_value);
	}
	i = print_zeros(d, min_val, i);
	if (flag.min_value != 0 || (flag.min_value == 0 && d != 0))
		putnbr(d);
	else
		i--;
	return (i + int_size(d));
}

int			print_digit(long long d, t_flags flag)
{
	int i;
	int min_val;

	i = 0;
	min_val = flag.min_value;
	if (flag.min_value != -1)
		flag.is_print_null = 0;
	if (int_size(d) > flag.min_value && (flag.min_value != 0 ||
		(flag.min_value == 0 && d != 0)))
		flag.min_value = int_size(d);
	if (flag.is_print_left)
		return (print_left(flag, d, min_val, i));
	else
		return (print_right(flag, d, min_val, i));
}
