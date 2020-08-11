NAME = libftprintf.a

SRCS = ft_atoi_i.c  \
		  ft_itoa_base.c \
		  ft_print_address.c \
		  ft_print_char.c \
		  ft_print_integer.c \
		  ft_print_percent.c \
		  ft_print_string.c \
		  ft_print_unsignedint.c \
		  ft_print_with_indent.c \
		  ft_printf.c \
		  ft_printf_utilities.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

LIBFT_NAME = libft.a

LIBFT_SRCS = $(wildcard libft/*.c)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
LIBFT_HEADER = libft/libft.h

HEADER = ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c -g

.PHONY = all clean fclean re create_libt

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS) $(LIBFT_SRCS) $(LIBFT_HEADER)
	make -C libft all
	cp $(LIBFT) .
	mv $(LIBFT_NAME) $(NAME)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(HEADER)
	$(CC) $(CFLAGS) $(SRCS) -I.

clean:
	rm -f $(OBJS)
	make -C libft clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean
re: fclean all