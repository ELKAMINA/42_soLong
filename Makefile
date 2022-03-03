CC = gcc -Wall -Werror -Wextra -g

NAME = so_long

SRC =  main.c\
		./ext_func/ft_strrchr.c \
		./ext_func/ft_strnstr.c \
		./ext_func/ft_split.c \
		./ext_func/ft_strncmp.c \
		./checks/check_file.c \
		./checks/check_file2.c \
		./checks/check_params.c \
		./checks/check_scene.c \
		./checks/check_scene2.c \
		./checks/check_scene3.c \
		./game/initialisations/initialisations.c \
		./game/initialisations/initialisations2.c \
		./game/initialisations/initialisations3.c \
		./game/moving/moving_r_l.c \
		./game/moving/moving_up.c \
		./game/moving/moving_down.c \
		./freeing/to_free.c \
		./freeing/cleaning.c \
		./game/getting_bgd/retrieve_bgd.c \
		./game/getting_bgd/retrieve_bgd2.c \
		./game/graphical_mngt/window_mngt.c \
		./game/graphical_mngt/window_mngt2.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_putchar_counting.c \
		./ft_printf/ft_putnbr_base.c \
		./ft_printf/ft_putnbr_counting.c \
		./ft_printf/ft_putstr_counting.c \

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