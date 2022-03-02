/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_bgd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:05:20 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/02 18:06:25 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	load_img_fail(t_soLong *game)
{
	write (1, "Img cannot load\n", 17);
	quit_game(game);
	exit (0);
	return (0);
}

void	init_decor(t_soLong *game)
{
	game->player->img->img = mlx_xpm_file_to_image(game->frame->mlx,
			PLAYER, &(game->player->img->width), &(game->player->img->height));
	if (!(game->player->img->img))
		load_img_fail(game);
	game->wall->img->img = mlx_xpm_file_to_image(game->frame->mlx,
			WALL, &(game->wall->img->width), &(game->wall->img->height));
	if (!game->wall->img->img)
		load_img_fail(game);
	game->coll->img->img = mlx_xpm_file_to_image(game->frame->mlx,
			COLL, &(game->coll->img->width), &(game->coll->img->height));
	if (!game->coll->img->img)
		load_img_fail(game);
	game->exit->img->img = mlx_xpm_file_to_image(game->frame->mlx,
			EXIT, &game->exit->img->width, &game->exit->img->height);
	if (!game->exit->img->img)
		load_img_fail(game);
	game->floor->img->img = mlx_xpm_file_to_image(game->frame->mlx,
			FLOOR, &game->floor->img->width, &game->floor->img->height);
	if (!game->floor->img->img)
		load_img_fail(game);
}

void	put_images(t_soLong *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->frame->mlx, game->frame->win,
		img, (y * IMG_SIZE), (x * IMG_SIZE));
}

void	get_the_right_image(char c, t_soLong *game, int i, int j)
{
	if (c == '1')
		put_images(game, game->wall->img->img, i, j);
	if (c == '0')
		put_images(game, game->floor->img->img, i, j);
	if (c == 'E')
		put_images(game, game->exit->img->img, i, j);
	if (c == 'C')
		put_images(game, game->coll->img->img, i, j);
	if (c == 'P')
		put_images(game, game->player->img->img, i, j);
}

void	get_ze_game(t_soLong *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->scene[i])
	{
		j = 0;
		while (game->scene[i][j])
		{
			get_the_right_image(game->scene[i][j], game, i, j);
			j++;
		}
		i++;
	}
	playing(game);
	mlx_loop(game->frame->mlx);
}
