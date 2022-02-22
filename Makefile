CC = gcc -Wall -Werror -Wextra -g

NAME = so_long

SRC =  main.c\
		./ext_func/ft_strchr.c \
		./ext_func/ft_strrchr.c \
		./ext_func/ft_strlen.c \
		./ext_func/ft_strnstr.c \
		./checks/check_file.c \
		./checks/check_params.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	# $(CC) -Imlx -c $< -o $@
	$(CC) -c $< -o $@

$(NAME) : $(OBJ)
	# make -C mlx
	# $(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	$(CC) -o $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean: clean
	 rm -f $(NAME)

re: fclean all

.PHONY : all clean bonus fclean re