#include "../../so_long.h"

void	init_struct_game(t_soLong *game, int fd)
{
	game->scene = get_stage(fd);
	init_struct_frame(game);
	init_struct_thing(game);
}

void	init_struct_frame(t_soLong *game)
{
	t_frame		frametest;

	game->frame = &frametest;
	game->frame->mlx = 0;
	game->frame->win = 0;
	game->frame->win_w = 0;
	game->frame->win_h = 0;
}

void	init_struct_img(t_soLong *game)
{
	t_img		imagep;
	t_img		imagec;
	t_img		imagew;
	t_img		imagee;
	t_img		imagef;

	game->player->img = &imagep;
	game->floor->img = &imagef;
	game->wall->img = &imagew;
	game->exit->img = &imagee;
	game->coll->img = &imagec;
	init_player(game);
	init_wall(game);
	init_coll(game);
	init_exit(game);
	init_floor(game);
}


void	init_struct_thing(t_soLong *game)
{
	t_thing		players;
	t_thing		floors;
	t_thing		walls;
	t_thing		exits;
	t_thing		colls;
	
	game->player = &players;
	game->floor = &floors;
	game->wall = &walls;
	game->coll = &colls;
	game->exit = &exits;
	game->player->pos_x = 0;
	game->player->pos_y = 0;
	game->player->total_nb = 0;
	game->floor->pos_x = 0;
	game->floor->pos_y = 0;
	game->floor->total_nb = 0;
	game->exit->pos_x = 0;
	game->exit->pos_y = 0;
	game->exit->total_nb = 0;
	game->coll->pos_x = 0;
	game->coll->pos_y = 0;
	game->coll->total_nb = 0;
	game->wall->pos_x = 0;
	game->wall->pos_y = 0;
	game->wall->total_nb = 0;
	init_struct_img(game);
}