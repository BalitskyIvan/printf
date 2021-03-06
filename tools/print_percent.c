/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:52:00 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 15:52:02 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	print_percent(t_flags flag)
{
	int i;

	i = 1;
	if (flag.is_print_left)
	{
		ft_putchar_fd('%', 1);
		i += print_whitespaces(flag.min_field, 1);
	}
	else
	{
		if (!flag.is_print_null)
			i += print_whitespaces(flag.min_field, 1);
		else
			i += print_zero(1, flag.min_field);
		ft_putchar_fd('%', 1);
	}
	return (i);
}
