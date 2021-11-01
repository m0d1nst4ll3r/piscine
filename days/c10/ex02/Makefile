SRCS	= ft_tail.c ft_tail_list.c ft_tail_err.c ft_tail_util.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_tail

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
