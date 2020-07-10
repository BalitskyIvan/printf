#ifndef PRINTF_H
# define PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct		Flag
{
	int		isPrintNull;
	int		isPrintLeft;
	int		minField;
	int		minValue;
	int		iterator;
	int		is_width_def;
	char	argType;
}					Flag;

typedef struct		Counter
{
	int		iterator;
	int		size;
}					Counter;

int					int_size(int d);
int					u_int_size(unsigned int u);
int					get_string_size(char *s);
int					sizeof_double(double d);
int					print_zero(int size, int min_arg_size);
int					print_char(char c, Flag flag);
int					print_string(char *s, Flag flag);
int					print_digit(int d, Flag flag);
int					print_x(unsigned int x, Flag flag);
int					print_p(unsigned long long p, Flag flag);
int					print_unsigned_dec(unsigned int u, Flag flag);
int					print_percent(Flag flag);
Counter				print_arg(Flag flag, va_list ap, char *format, Counter counter);
int					print_whitespaces(int count, int arg_size);
void				set_max_arg_size(Flag *flag, char *format, int i);
void				set_min_field_size(Flag *flag, va_list ap, char *format, int i);
void				set_left_or_zero(Flag *flag, char *format, int i);
void				set_arg(Flag *flag, char *format, int i);
int					ft_isdigit(int ch);
int					is_right_arg(char c);
int					parse_args(Flag flag, char *format, va_list ap, int i);
Flag				parse_flags(char *format, va_list ap, int i);
int					ft_printf(char *format, ...);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
#endif