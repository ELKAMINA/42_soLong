#include "../so_long.h"

int	destroy_base(t_soLong *game)
{
	if (game->floor != NULL)
		mlx_destroy_image(game->frame->mlx, game->floor);
  if (game->wall != NULL)
		mlx_destroy_image(game->frame->mlx, game->wall);
  if (game->exit != NULL)
    mlx_destroy_image(game->frame->mlx, game->exit);
  if (game->player != NULL)
    mlx_destroy_image(game->frame->mlx, game->player);
  if (game->coll != NULL)
    mlx_destroy_image(game->frame->mlx, game->coll);
	return (0);
}

int	destroy_all_images(t_soLong *game)
{
	destroy_base(game);
	return (0);
}