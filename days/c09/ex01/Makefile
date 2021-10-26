LIBDIR	= includes/
SRCDIR	= srcs/
SRC		= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS	= $(addprefix ${SRCDIR},${SRC})

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc
LIB		= ar rc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${LIBDIR}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
