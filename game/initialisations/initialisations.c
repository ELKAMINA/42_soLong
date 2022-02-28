#include "../../so_long.h"

void	init_struct_game(t_soLong *game, int fd)
{
	game->scene = get_stage(fd);
	init_struct_frame(game);
	init_struct_thing(game);
}

void	init_struct_frame(t_soLong *game)
{
	// A FREE
	game->frame = malloc(sizeof(t_frame));
	game->frame->mlx = 0;
	game->frame->win = 0;
	game->frame->win_w = 0;
	game->frame->win_h = 0;
}

void	init_struct_img(t_soLong *game)
{
	// A FREE
	game->player->img = malloc(sizeof(t_img));
	game->wall->img = malloc(sizeof(t_img));
	game->coll->img = malloc(sizeof(t_img));
	game->exit->img = malloc(sizeof(t_img));
	game->floor->img = malloc(sizeof(t_img));
	init_player(game);
	init_wall(game);
	init_coll(game);
	init_exit(game);
	init_floor(game);
}


void	init_struct_thing(t_soLong *game)
{
	// A FREE
	game->player = malloc(sizeof(t_thing));
	game->wall = malloc(sizeof(t_thing));
	game->coll = malloc(sizeof(t_thing));
	game->exit = malloc(sizeof(t_thing));
	game->floor = malloc(sizeof(t_thing));
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