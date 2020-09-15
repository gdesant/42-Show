SRC = utils/ft_atoi.c \
		utils/ft_bzero.c \
		utils/ft_isdigit.c \
		utils/ft_strchr.c \
		utils/ft_strdup.c \
		utils/ft_strlen.c \
		utils/ft_substr.c \
		utils/ft_itoa.c \
		utils/ft_strnew.c \
		utils/ft_strjoin.c \
		utils/ft_itox.c \
		utils/get_prec.c \
		utils/print_back.c \
		process/process_char.c \
		process/process_str.c \
		process/process_int.c \
		process/process_hex.c \
		process/process_u.c \
		process/process_p.c \
		process/process_percent.c \
		utils/prec_flag_utils.c \
		ft_printf.c \	

OBJS    = ${SRCS:.c=.o}

NAME    = libftprintf.a

CC        = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $(<:.c=.o) -I includes

$(NAME):    ${OBJS}
	ar    rc ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:    clean
	rm -f ${NAME}

re:        fclean all

.PHONY:        all clean fclean re