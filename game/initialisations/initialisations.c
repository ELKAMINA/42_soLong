#include "../../so_long.h"

void	init_struct_game(t_soLong *game, int fd)
{
	game->scene = get_stage(fd);
	game->p = 0;
	game->w = 0;
	game->v = 0;
	game->e = 0;
	game->c = 0;
	game->coll = NULL;
	game->floor = NULL;
	game->wall = NULL;
	game->player = NULL;
	game->exit = NULL;
	game->img_height = 0;
	game->img_width = 0;
}

void	init_struct_frame(t_soLong *game)
{
	game->frame->mlx = 0;
	game->frame->win = 0;
	game->frame->win_w = 0;
	game->frame->win_h = 0;
}