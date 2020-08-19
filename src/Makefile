NAME		= libftprintf.a

INC_DIR		= header/
SRC_DIR		= ./sources

HEADERS		= ft_printf.h
SRC = \
		libft/ft_strchr.c \
		libft/ft_strlen.c \
		sources/ft_atoi_i.c \
		sources/ft_flags.c \
		sources/ft_floating.c \
		sources/ft_hash.c \
		sources/ft_itoa_base.c \
		sources/ft_length.c \
		sources/ft_long_float.c \
		sources/ft_print.c \
		sources/ft_print_address.c \
		sources/ft_print_char_string.c \
		sources/ft_print_float.c \
		sources/ft_print_integer.c \
		sources/ft_print_percent.c \
		sources/ft_print_unsignedint.c \
		sources/ft_print_with_indent.c \
		sources/ft_printf.c

OBJS = $(SRC:.c=.o)

LIBFT = ./libft

WFL = -Wall -Wextra -Werror

IFL = -I $(INC_DIR)

SRCS = $(addprefix $(SRC_DIR))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)/
	cp $(LIBFT)/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: $(SRC_DIR)/%.c
	gcc $(WFL) $(IFL) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT)/ clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT)/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re