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
	if (!game->player->img)
		return ;
	game->wall->img = malloc(sizeof(t_img));
	if (!game->wall->img)
		return ;
	game->coll->img = malloc(sizeof(t_img));
	if (!game->coll->img)
		return ;
	game->exit->img = malloc(sizeof(t_img));
	if (!game->exit->img)
		return ;
	game->floor->img = malloc(sizeof(t_img));
	if (!game->floor->img)
		return ;
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
	if (!game->player)
		return ;
	game->wall = malloc(sizeof(t_thing));
	if (!game->wall)
		return ;
	game->coll = malloc(sizeof(t_thing));
	if (!game->coll)
		return ;
	game->exit = malloc(sizeof(t_thing));
	if (!game->exit)
		return ;
	game->floor = malloc(sizeof(t_thing));
	if (!game->floor)
		return ;
	init_thing_player(game);
	init_thing_wall(game);
	init_thing_coll(game);
	init_thing_exit(game);
	init_thing_floor(game);
	init_struct_img(game);
}