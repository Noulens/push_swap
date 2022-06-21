NAME	=	push_swap

CFILES	=	./srcs/ft_build_stack.c\
			./srcs/ft_push.c\
			./srcs/ft_reverse_rotate.c\
			./srcs/ft_rotate.c\
			./srcs/ft_sort.c\
			./srcs/ft_swap.c\
			./srcs/ft_utils_a.c\
			./srcs/main.c

OBJECTS = $(CFILES:.c=.o)

LIB_PATH = libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

all: subsystem $(NAME)

subsystem:
	make -C $(LIB_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB_PATH)libft.a -o $(NAME)

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)

re: fclean all

call: all clean
	make -C $(LIB_PATH) fclean

.PHONY	: all clean fclean re call