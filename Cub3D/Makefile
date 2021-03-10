NAME	= Cub3D
SRCS	= ./srcs/cub3d.c\
			./srcs/draw_walls.c\
			./srcs/init.c\
			./srcs/inputs.c\
			./srcs/player.c\
			./srcs/raycast.c\
			./srcs/ray_utils.c\
			./srcs/utils.c\
			./srcs/printsprite.c\
			./srcs/save_bmp.c\
			./srcs/game.c\

OBJS	= ${SRCS:.c=.o}
INCS	= ./include/
RM		= rm -f
CC		= clang
CFLAGS	= -Wall -Wextra -Werror

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