# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmallado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 19:21:22 by lmallado          #+#    #+#              #
#    Updated: 2020/07/13 19:21:30 by lmallado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = includes/

SRCS = ./libft/ft_putchar_fd.c \
	./libft/ft_putnbr_fd.c \
	./libft/ft_putstr_fd.c \
	./libft/ft_isdigit.c \
	./SRCS/printf.c \
	./SRCS/print_arg.c \
	./SRCS/parse_flags.c \
	./tools/parse_arg_tool.c \
	./tools/parse_min_field.c \
	./tools/parse_min_val.c \
	./tools/convert_hex.c \
	./tools/print_tools.c \
	./tools/print_c.c \
	./tools/print_s.c \
	./tools/print_d.c \
	./tools/print_u.c \
	./tools/print_x.c \
	./tools/print_p.c \
	./tools/print_percent.c

O_FILE = $(patsubst %.c,%.o,$(SRCS))
D_FILE = $(patsubst %.c,%.d,$(SRCS))


FLAGS = -Wall

all: $(NAME)

$(NAME): $(O_FILE)
	ar rc $(NAME) $?
	ranlib $(NAME)

%.o: %.c ./includes/printf.h
	gcc -c $(FLAGS) -I$(HEADER) -c $< -o $@ -MD

clean:
	rm -f $(O_FILE)
	rm -f $(D_FILE)

fclean: clean
	rm -f $(NAME)

re:		fclean all

include $(wildcards $(D_FILE))

.PHONY : all clean fclean re
