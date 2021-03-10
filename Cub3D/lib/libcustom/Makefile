NAME	= libmap.a

SRCS = 	ft_printf/ft_printf.c \
	ft_printf/utils/ft_atoi.c \
	ft_printf/utils/ft_bzero.c \
	ft_printf/utils/ft_isdigit.c \
	ft_printf/utils/ft_strchr.c \
	ft_printf/utils/ft_strdup.c \
	ft_printf/utils/ft_strlen.c \
	ft_printf/utils/ft_substr.c \
	ft_printf/utils/ft_itoa.c \
	ft_printf/utils/ft_strnew.c \
	ft_printf/utils/ft_strjoin.c \
	ft_printf/utils/ft_itox.c \
	ft_printf/utils/get_prec.c \
	ft_printf/utils/print_back.c \
	ft_printf/process/process_char.c \
	ft_printf/process/process_str.c \
	ft_printf/process/process_int.c \
	ft_printf/process/process_hex.c \
	ft_printf/process/process_u.c \
	ft_printf/process/process_p.c \
	ft_printf/process/process_percent.c \
	ft_printf/utils/prec_flag_utils.c \
	map/utils.c \
	map/utils2.c \
	map/ft_split.c \
	map/map_init.c \
	map/parse_map.c \
	map/parse_map_utils.c \
	map/free_map.c\
	map/check_map_error.c\
	map/error_utils.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \


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