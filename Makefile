
NAME 			= cub3D

SRCS_LIST		=	main.c \
					gnl_utils.c \
					gnl.c \
					free_data.c


FOLDER			= srcs

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

# SRCS_BONUS		= $(addprefix ${FOLDER}/, ${SRCS_LIST_BONUS})

OBJS			= ${SRCS:.c=.o}

# OBJS_BONUS		= ${SRCS_BONUS:.c=.o}

HEADER			= header

OBJDIR			= obj

CC				= gcc

CFLAGS 			= -Wall -Wextra -Werror -g

RM				= rm -rf

LINK			= ar rc 

MYLIB 			= mylib.a

PATH_MLX_LINUX 	= ./mlx/

MLX_LINUX		= ./mlx/libmlx_Linux.a

all:		${NAME}

%.o: %.c
			${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

$(NAME):	${OBJS}
			${LINK} ${MYLIB} ${OBJS}
			ranlib ${MYLIB}
			make -C ${PATH_MLX_LINUX}
			${CC} ${FLAGS} -o3 ${MYLIB} ${MLX_LINUX} -lm -lbsd -lX11 -lXext -o ${NAME}	

clean:
			${RM} ${OBJS}  ${OUT} ${OBJDIR}
# ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME} ${MYLIB}

move:			${OBJS}
				mkdir -p ${OBJDIR} && mv ${OBJS} ${OBJDIR}

# bonus:		${OBJS_BONUS}
# 			${LINK} ${MYLIB} ${OBJS_BONUS}
# 			ranlib ${MYLIB}
# 			make -C ${PATH_MLX_LINUX}
# 			${CC} ${FLAGS} -o3 ${MYLIB} ${MLX_LINUX} -lm -lbsd -lX11 -lXext -o $(NAME)

# valgrind:	${NAME}
# 			@valgrind \
# 			--leak-check=full --tool=memcheck \
# 			--show-reachable=yes \
# 			--track-fds=yes \
# 			--errors-for-leak-kinds=all \
# 			--show-leak-kinds=all \
# 			./${NAME} maps/map1.ber

# norminette:	${SRCS} ${SRCS_BONUS}
# 			@norminette header/So_long.h srcs/* bonus_files/*

re:			fclean all

# rebonus:	fclean bonus

# .PHONY: 	all clean fclean re rebonus bonus valgrind norminette move

# -g3 -fsanitize=address
