NAME = libftprintf.a

HEADER = ./includes/printf.h

SRCS = ./libft/ft_putchar_fd.c \
	./libft/ft_isdigit.c \
	./SRCS/printf.c \
	./SRCS/print_arg.c \
	./SRCS/parse_flags.c \
	./tools/parse_arg_tool.c \
	./tools/print_tools.c \
	./tools/print_c.c \
	./tools/print_s.c \
	./tools/print_d.c
	
	

SRCS_O = ft_putchar_fd.o \
	ft_isdigit.o \
	printf.o \
	print_arg.o \
	parse_flags.o \
	parse_arg_tool.o \
	print_tools.o \
	print_c.o \
	print_s.o \
	print_d.o

BONUS_SRCS =

O_FILE = $(SRCS:.c=.o)

O_BONUS = $(BONUS_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(HEADER) $(O_FILE)
	ar rc $(NAME) $(SRCS_O)
	ranlib $(NAME)

$(O_FILE): %.o:%.c $(HEADER)
	gcc -c $(FLAGS) -I./includes $<

clean:
	rm -rf $(SRCS_O)
	rm -rf $(O_BONUS)

fclean: clean
	rm -rf $(NAME)

re:		fclean all

.PHONY : all clean fclean re
