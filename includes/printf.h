/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:12:29 by lmallado          #+#    #+#             */
/*   Updated: 2020/07/13 13:12:32 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_flags
{
	int				is_print_null;
	int				is_print_left;
	int				min_field;
	int				min_value;
	int				iterator;
	char			arg_type;
}					t_flags;

typedef struct		s_counter
{
	int				iterator;
	int				size;
}					t_counter;

int					int_size(long long d);
int					u_int_size(unsigned int u);
int					get_string_size(char *s);
int					sizeof_double(double d);
int					print_zero(int size, int min_arg_size);
int					print_char(char c, t_flags flag);
int					print_string(char *s, t_flags flag);
int					print_digit(long long d, t_flags flag);
int					print_x(unsigned int x, t_flags flag);
int					print_p(unsigned long long p, t_flags flag);
int					print_unsigned_dec(unsigned int u, t_flags flag);
int					print_percent(t_flags flag);
t_counter			print_arg(t_flags flag, va_list ap,
char *format, t_counter counter);
int					print_whitespaces(int count, int arg_size);
int					set_max_arg_size(t_flags *flag, va_list ap,
char *format, int i);
int					set_min_field_size(t_flags *flag, va_list ap,
char *format, int i);
void				set_left_or_zero(t_flags *flag, char *format, int i);
void				set_arg(t_flags *flag, char *format, int i);
int					ft_isdigit(int ch);
int					is_right_arg(char c);
int					parse_args(t_flags flag, char *format, va_list ap, int i);
t_flags				parse_flags(char *format, va_list ap, int i);
char				*convert_hex(int is_upper, unsigned int val);
int					ft_printf(char *format, ...);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(long long n, int fd);
#endif
