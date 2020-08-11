# NAME = libftprintf.a

# SRCS = sources/*.c \

# OBJS = $(SRCS:.c=.o)

# LIBFT = libft/libft.a

# LIBFT_NAME = libft.a

# LIBFT_SRCS = $(wildcard libft/*.c)
# LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
# LIBFT_HEADER = libft/libft.h

# HEADER = header/ft_printf.h

# CC = gcc

# CFLAGS = -Wall -Wextra -Werror -c -g

# .PHONY = all clean fclean re create_libt

# all: $(NAME)

# $(NAME): $(OBJS) $(LIBFT_OBJS) $(LIBFT_SRCS) $(LIBFT_HEADER)
# 	make -C libft all
# 	cp $(LIBFT) .
# 	mv $(LIBFT_NAME) $(NAME)
# 	ar rc $(NAME) $(OBJS)

# $(OBJS): $(SRCS) $(HEADER)
# 	$(CC) $(CFLAGS) $(SRCS) -I header
# 	mv *.o sources
	
# clean:
# 	rm -f $(OBJS)
# 	rm -rf a.*
# 	make -C libft clean
# fclean: clean
# 	rm -f $(NAME)
# 	make -C libft fclean
# re: fclean all

# #
NAME = printf

SRCS = sources/*.c \

LIBFT = libft/libft.a

LIBFT_NAME = libft.a

HEADER = ft_printf.h

CC = gcc

CFLAGS = -g 

.PHONY = all clean fclean re 

all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT_OBJS) $(LIBFT_SRCS) $(LIBFT_HEADER)
	make -C libft all
	mv $(LIBFT) .
	gcc -g $(SRCS) -L. -lft -I header
	./a.out | cat -e
	
clean:
	rm -rf a.* *.a
	rm -rf sources/*.o
	rm -rf *.o
fclean: clean
		make -C libft clean
re: fclean all
