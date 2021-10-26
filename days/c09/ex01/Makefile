DIR		= srcs/

SRCSN	= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS	= ${DIR}${SRCSN}

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}
            
all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re 
