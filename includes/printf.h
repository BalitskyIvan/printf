#ifndef PRINTF_H
# define PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct		Flag
{
	int		isPrintScreen;
	int		isPrintNull;
	int		isPrintLeft;
	int		minField;
	int		minValue;
	int		iterator;
	char	argType;
}					Flag;
int					set_max_arg_size(Flag *flag, char *format, int i);
int					set_min_field_size(Flag *flag, char *format, int i);
void				set_screen(Flag *flag, char c);
void				set_left(Flag *flag, char c);
void				set_zero(Flag *flag, char c);
int					ft_isdigit(int ch);
int					parse_args(Flag flag, char *format, va_list ap, int i);
Flag				parse_flags(char *format, int i);
int					ft_printf(char *format, ...);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
#endif