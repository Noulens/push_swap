CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	./srcs/main.c\
			./srcs/

OBJS	=	${SRCS:.c=.o}

NAME	=	push_swap		

HEADERS	=	-I ./includes

${NAME}: ${OBJS}
	${MAKE} all -C ./libft
	cp libft/libft.a .
	${CC} -o $@ $^

all : ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${HEADERS} -o $@ -c $^ -g -L libft/ -lft

clean :
	${MAKE} clean -C ./libft
	rm -rf ${OBJS} *.o *.a

fclean : clean
	${MAKE} fclean -C ./libft
	rm -rf ${NAME}

re : fclean all