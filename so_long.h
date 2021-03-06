/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:48:49 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/02 18:10:50 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "minilibx/include/mlx.h"

# define FLOOR "images/ground.xpm"
# define WALL "images/wall.xpm"
# define COLL "images/coll.xpm"
# define EXIT "images/exit.xpm"
# define END "images/end.xpm"
# define PLAYER "images/player.xpm"

# define IMG_SIZE	80

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		width;
	int		height;
	int		ratio;
}	t_img;

typedef struct s_thing
{
	int		pos_x;
	int		pos_y;
	int		total_nb;
	int		total_moves;
	int		nb_of_coll;
	t_img	*img;
}	t_thing;

typedef struct s_frame
{
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
}	t_frame;

typedef struct s_soLong
{
	char	**scene;
	t_frame	*frame;
	t_thing	*player;
	t_thing	*wall;
	t_thing	*floor;
	t_thing	*coll;
	t_thing	*exit;
}	t_soLong;

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

int		check_create(int argc, char *argv[]);
int		check_name_arg(char *argv[]);
int		check_file(char *argv);
int		check_images(void);
char	**get_stage(int fd);
char	**create_map(char *final, int fd);
void	invalid_char_inmap(t_soLong *game);
void	invalid_map_msg(char *final);
void	check_if_empty(char *buf);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		double_newline(char *s);
void	init_struct_game(t_soLong *game, int fd);
void	checks(t_soLong *game);
void	count_initials(t_soLong *game);
void	increment(t_soLong *game, char c);
void	check_validity(t_soLong *game);
void	check_walls(t_soLong *game);
int		check_square(t_soLong *game);
void	check_fence(t_soLong *game);
void	check_first_last_line(t_soLong *game, char *lineOne);
void	check_intermediate_lines(t_soLong *game, char *lineOne);
void	freeing(char **game);
void	free_crash_init(t_soLong *game);
void	init_struct_frame(t_soLong *game);
void	init_player(t_soLong *game);
void	init_coll(t_soLong *game);
void	init_exit(t_soLong *game);
void	init_wall(t_soLong *game);
void	init_floor(t_soLong *game);
void	init_end(t_soLong *game);
void	init_struct_thing(t_soLong *game);
void	init_struct_img(t_soLong *game);
void	get_width_height(t_soLong *game);
void	init_thing_player(t_soLong *game);
void	init_thing_wall(t_soLong *game);
void	init_thing_coll(t_soLong *game);
void	init_thing_exit(t_soLong *game);
void	init_thing_floor(t_soLong *game);
void	get_background(t_soLong *game);
int		get_mlx_win(t_soLong *game);
void	get_game_base(t_soLong *game);
void	init_decor(t_soLong *game);
void	put_images(t_soLong *game, void *img, int x, int y);
void	get_the_right_image(char c, t_soLong *game, int i, int j);
void	check_validity_bis(t_soLong *game);
void	get_ze_game(t_soLong *game);
void	playing(t_soLong *game);
int		keypress(int keycode, t_soLong *game);
int		ft_strrchr(const char *s, int c);
int		ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
int		destroy_all_images(t_soLong *game);
int		destroy_base(t_soLong *game);
int		quit_game(t_soLong *game);
void	init_struct_pos(t_soLong *game);
void	exit_return(void);
void	get_pos(t_soLong *game);
void	move_r(t_soLong *game, int x, int y);
void	move_l(t_soLong *game, int x, int y);
void	get_new_scene(t_soLong *game, int x, int y, int coll);
void	get_end_scene(t_soLong *game, int x, int y);
void	moving_backward(t_soLong *game);
void	moving_forward(t_soLong *game);
void	moving_up(t_soLong *game);
void	move_u(t_soLong *game, int x, int y);
void	moving_down(t_soLong *game);
void	move_d(t_soLong *game, int x, int y);

#endif