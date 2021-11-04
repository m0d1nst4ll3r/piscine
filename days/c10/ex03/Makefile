SRCS	= ft_hexdump.c ft_hexdump_util.c ft_hexdump_util2.c ft_hexdump_util3.c ft_hexdump_err.c ft_hexdump_print.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_hexdump

CC      = gcc
RM      = rm -f

CFLAGS  = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I .

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:     all clean fclean re
