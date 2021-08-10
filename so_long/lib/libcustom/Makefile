NAME	= libmap.a

SRCS = ft_printf/utils/ft_atoi.c \
	ft_printf/utils/ft_bzero.c \
	ft_printf/utils/ft_strchr.c \
	ft_printf/utils/ft_strdup.c \
	ft_printf/utils/ft_strlen.c \
	ft_printf/utils/ft_substr.c \
	ft_printf/utils/ft_itoa.c \
	ft_printf/utils/ft_strnew.c \
	ft_printf/utils/ft_strjoin.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	map/map_init.c \
	map/free_map.c \
	map/acquire_map.c \
	map/vector2.c \
	map/alert_map_error.c \
	map/check_map_error.c \
	map/precheck.c \
	map/assign_map_positions.c \

OBJS    = ${SRCS:.c=.o}

CC        = gcc

CFLAGS = -Wall -Wextra -Werror 

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $(<:.c=.o) -I includes

$(NAME):    ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:    clean
	rm -f ${NAME}

re:        fclean all

.PHONY:        all clean fclean re