/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:50:03 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 18:50:20 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char	*set_hex(int is_upper)
{
	if (!is_upper)
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

static char	*write_res(int count, unsigned int val, char *hex)
{
	char	*res;

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

char		*convert_hex(int is_upper, unsigned int val)
{
	char			*res;
	char			*hex;
	int				count;
	unsigned int	val_copy;

	count = 0;
	val_copy = val;
	hex = set_hex(is_upper);
	if (val == 0)
	{
		if (!(res = malloc(2)))
			return ("n");
		res[1] = '\0';
		res[0] = '0';
		return (res);
	}
	while (val_copy > 0)
	{
		val_copy /= 16;
		count++;
	}
	return (write_res(count, val, hex));
}
