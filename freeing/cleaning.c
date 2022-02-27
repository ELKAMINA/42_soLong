#include "../so_long.h"

int	destroy_base(t_soLong *game)
{
  printf("%p\n", game->floor->img);
	if (game->floor->img != NULL)
		mlx_destroy_image(game->frame->mlx, game->floor->img);
  if (game->wall->img != NULL)
		mlx_destroy_image(game->frame->mlx, game->wall->img);
  if (game->exit->img != NULL)
    mlx_destroy_image(game->frame->mlx, game->exit->img);
  if (game->player->img != NULL)
    mlx_destroy_image(game->frame->mlx, game->player->img);
  if (game->coll->img != NULL)
    mlx_destroy_image(game->frame->mlx, game->coll->img);
	return (0);
}

int	destroy_all_images(t_soLong *game)
{
	destroy_base(game);
	return (0);
}