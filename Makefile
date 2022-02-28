CC = gcc -Wall -Werror -Wextra -g

NAME = so_long

SRC =  main.c\
		./ext_func/ft_strrchr.c \
		./ext_func/ft_strnstr.c \
		./ext_func/ft_split.c \
		./checks/check_file.c \
		./checks/check_params.c \
		./checks/check_scene.c \
		./checks/check_scene2.c \
		./game/initialisations/initialisations.c \
		./game/initialisations/initialisations2.c \
		./game/moving/moving_r_l.c \
		./freeing/to_free.c \
		./freeing/cleaning.c \
		./game/getting_bgd/retrieve_bgd.c \
		./game/getting_bgd/retrieve_bgd2.c \
		./game/graphical_mngt/window_mngt.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) -I/usr/include -Iminilibx -c $< -o $@
	# $(CC) -c $< -o $@

$(NAME) : $(OBJ)
	make -C minilibx
	$(CC) $(OBJ) -lm -lz -o $(NAME) minilibx/libmlx_Linux.a -lXext -lX11
	# $(CC) -o $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean: clean
	 rm -f $(NAME)

re: fclean all

.PHONY : all clean bonus fclean re
