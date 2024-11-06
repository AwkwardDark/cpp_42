SRC			=	Account /
				tests

SRCS		= $(addsuffix .cpp, ${SRC})

OBJS		= ${SRCS:.cpp=.o}

NAME		= account

CC			= c++

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -std=c++98

.cpp.o:
			${CC} ${CFLAGS} -I./includes -c $< -o ${<:.cpp=.o}

$(NAME):	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re