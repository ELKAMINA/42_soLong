#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"
# include "minilibx/include/mlx.h"

// Chemin d'acces aux images
# define FLOOR "images/ground.xpm"
# define WALL "images/wall.xpm"
# define COLL "images/coll.xpm"
# define EXIT "images/exit.xpm"
# define EMPTY "images/empty.xpm"
# define PLAYER "images/player.xpm"
// # define PLAYER "assets/P_W.xpm"
// # define PLAYER_A "assets/P_A.xpm"
// # define PLAYER_S "assets/P_S.xpm"
// # define PLAYER_D "assets/P_D.xpm"


# define IMG_SIZE	80

//Main struct

typedef struct s_soLong
{
	char	**scene;
	void	*floor;
	void	*wall;
	void 	*coll;
	void	*player;
	void	*exit;
	int	  	img_width;
	int	  	img_height;
	int		p;
	int		w;
	int		v;
	int		e;
	int		c;
	struct s_frame *frame;
}   t_soLong;

typedef struct s_frame
{
    void *mlx;
    void *win;
    int   win_w;
    int   win_h;
}   t_frame;

// typedef struct s_img_data
// {
//     void *img;
//     int	  bits_per_pixel;
// 	int	  line_length;
// 	int	  endian;
//     char  *rpath;
	
//     char  *addr;

// }   t_img_data;

// Check params and get map
int        check_create(int argc, char *argv[]);
int        check_name_arg(char *argv[]);
int        check_file(char *argv);
char	   **get_stage(int fd);
void	    init_struct_game(t_soLong *game, int fd);

// Check map validity
void    verif_scene(t_soLong *game);
void    count_initials(t_soLong *game);
void    increment(t_soLong *game, char c);
void    check_validity(t_soLong *game);
void    check_walls(t_soLong *game);
int     check_square(t_soLong *game);
void    check_fence(t_soLong *game);
void    check_first_last_line(t_soLong *game, char *lineOne);
void    check_intermediate_lines(t_soLong *game, char *lineOne);

// Free when parsing 
void    freeing(char    **game);

// Drawing
void	init_struct_frame(t_frame *frame);
void    get_width_height(t_frame *my_frame, t_soLong *game);
void    get_background(t_frame *my_frame, t_soLong *game);
void    get_mlx_win(t_frame *frame, t_soLong *game);
// void    my_mlx_put_pixel(t_img_data *img, int x, int y, int color);
void    get_game_base(t_soLong *game);
void 	init_decor(t_soLong *game, t_frame *frame);
void 	put_images(t_soLong *game, void *img, int x, int y);
void 	get_the_right_image(char c, t_soLong *game, int i, int j);
// void    init_struct_imgData(t_img_data *img);
void    get_ze_game(t_soLong *game);




// External functions
int	        ft_strrchr(const char *s, int c);
int	        ft_strnstr(const char *haystack, const char *needle, size_t len);
char	    **ft_split(char const *s, char c);









#endif