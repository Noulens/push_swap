CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	./srcs/
			./srcs/

OBJS	=	${SRCS:.c=.o}

NAME	=	push_swap		

HEADERS	=	-I ./includes

${NAME}: ${OBJS}
	${MAKE} all -C ./libft
	${CC} -o $@ $^
#	cp libft/libft.a .
#	METTRE CMD DE COMPILE AVEC LIBFT

all : ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${HEADERS} -o $@ -c $^ -g -L libft/ -lft

clean :
	${MAKE} clean -C ./libft
	rm -rf ${OBJS} *.o

fclean : clean
	${MAKE} fclean -C ./libft
	rm -rf ${NAME}

re : fclean all