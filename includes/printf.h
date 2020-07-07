#ifndef PRINTF_H
# define PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct		Flag
{
	int		isPrintNull;
	int		isPrintLeft;
	int		minField;
	int		minValue;
	int		iterator;
	char	argType;
}					Flag;

int					int_size(int d);
void				print_zero(int arg, int min_arg_size);
void				print_char(char c, Flag flag);
void				print_string(char *s, Flag flag);
void				print_digit(int d, Flag flag);
int					print_arg(Flag flag, va_list ap, char *format, int i);
void				print_percent(Flag flag);
int					get_string_size(char *s);
void				print_whitespaces(int count, int arg_size);
void				set_max_arg_size(Flag *flag, char *format, int i);
void				set_min_field_size(Flag *flag, char *format, int i);
void				set_left_or_zero(Flag *flag, char *format, int i);
void				set_arg(Flag *flag, char *format, int i);
int					ft_isdigit(int ch);
int					is_right_arg(char c);
int					parse_args(Flag flag, char *format, va_list ap, int i);
Flag				parse_flags(char *format, int i);
int					ft_printf(char *format, ...);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
#endif