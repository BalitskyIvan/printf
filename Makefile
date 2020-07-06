NAME = libftprintf.a

HEADER = printf.h \
	./includes/libft.h

SRCS = ./includes/ft_putstr_fd.c \
	./includes/ft_putnbr_fd.c \
	./includes/ft_putchar_fd.c \
	./SRCS/printf.c \
	./SRCS/print_X.c \
	./SRCS/parse_args.c

SRCS_O = ft_putchar_fd.o \
	ft_putnbr_fd.o \
	ft_putstr_fd.o \
	printf.o \
	print_X.o \
	parse_args.o

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
