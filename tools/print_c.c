/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:51:13 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 15:51:15 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	print_char(char c, t_flags flag)
{
	int i;

	i = 1;
	if (flag.is_print_left)
	{
		ft_putchar_fd(c, 1);
		i += print_whitespaces(flag.min_field, 1);
	}
	else
	{
		i += print_whitespaces(flag.min_field, 1);
		ft_putchar_fd(c, 1);
	}
	return (i);
}
