NAME	= so_long

SRCS	= ./srcs/so_long.c\
		  ./srcs/utils.c\
		  ./srcs/init.c\
		  ./srcs/inputs.c\
		  ./srcs/movement.c\
		  ./srcs/debug.c\
		  ./srcs/printer/printer.c\
		  ./srcs/printer/case_printer.c\
		  ./srcs/printer/printer_utils.c\

OBJS	= ${SRCS:.c=.o}
INCS	= ./include/
RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror  -g -fsanitize=address

Lib_MLXLINUX = ./lib/minilibx_linux/
MLX_LINUX 	= ${Lib_MLXLINUX}libmlx.a

Lib_MAP = ./lib/libcustom/
MAPLIB 	= ${Lib_MAP}libmap.a

${NAME}: ${OBJS}
	make -C ${Lib_MLXLINUX}
	make -C ${Lib_MAP}
	${CC} ${CFLAGS} -o3 ${OBJS} -I ${INCS} ${MLX_LINUX} ${MAPLIB} -lm -lbsd -lX11 -lXext -o $(NAME)

sanitize: ${OBJS}
	make -C ${Lib_MLXLINUX}
	make -C ${Lib_MAP}
	${CC} ${CFLAGS}	-fsanitize=address -o3 ${OBJS} -I ${INCS} ${MLX_LINUX} ${MAPLIB} -lm -lbsd -lX11 -lXext -o $(NAME)

all:${NAME}

clean:
	${RM} ${OBJS}

allclean:
	${RM} ${OBJS}
	@make clean -C $(Lib_MLXLINUX) 
	@make clean -C $(Lib_MAP)

fclean: clean
	${RM} ${NAME}

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader */*.[ch]

.PHONY: all clean fclean re .c.o norm