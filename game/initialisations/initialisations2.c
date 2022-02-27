#include "../../so_long.h"

void	init_player(t_soLong *game)
{
	game->player->img->img = NULL;
	game->player->img->addr = NULL;
	game->player->img->bits_per_pixel = 0;
	game->player->img->line_lenght = 0;
	game->player->img->endian = 0;
	game->player->img->width= 0;
	game->player->img->height= 0;
	game->player->img->ratio= 0;
}

void	init_wall(t_soLong *game)
{
	game->wall->img->img = NULL;
	game->wall->img->addr = NULL;
	game->wall->img->bits_per_pixel = 0;
	game->wall->img->line_lenght = 0;
	game->wall->img->endian = 0;
	game->wall->img->width= 0;
	game->wall->img->height= 0;
	game->wall->img->ratio= 0;
}

void	init_coll(t_soLong *game)
{
	game->coll->img->img = NULL;
	game->coll->img->addr = NULL;
	game->coll->img->bits_per_pixel = 0;
	game->coll->img->line_lenght = 0;
	game->coll->img->endian = 0;
	game->coll->img->width= 0;
	game->coll->img->height= 0;
	game->coll->img->ratio= 0;
}

void	init_exit(t_soLong *game)
{
	game->exit->img->img = NULL;
	game->exit->img->addr = NULL;
	game->exit->img->bits_per_pixel = 0;
	game->exit->img->line_lenght = 0;
	game->exit->img->endian = 0;
	game->exit->img->width= 0;
	game->exit->img->height= 0;
	game->exit->img->ratio= 0;
}


void	init_floor(t_soLong *game)
{
	game->floor->img->img = NULL;
	game->floor->img->addr = NULL;
	game->floor->img->bits_per_pixel = 0;
	game->floor->img->line_lenght = 0;
	game->floor->img->endian = 0;
	game->floor->img->width= 0;
	game->floor->img->height= 0;
	game->floor->img->ratio= 0;
}