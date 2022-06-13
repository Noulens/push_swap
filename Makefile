CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g

SRCS	=	#METTRE SRC

OBJS	=	${SRCS:.c=.o}

NAME	=	#METTRE NAME		

HEADERS	=	#METTRE HEADER

${NAME}: ${HEADERS} ${OBJS}
	${MAKE} all -C ./libft
	cp libft/libft.a .
#	METTRE CMD DE COMPILE AVEC LIBFT

all : ${NAME}

clean :
	${MAKE} clean -C ./libft
	rm -rf ${OBJS} *.o

fclean : clean
	${MAKE} fclean -C ./libft
	rm -rf ${NAME}

re : fclean all