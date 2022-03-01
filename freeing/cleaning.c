/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:35:45 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/01 21:35:48 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	destroy_base(t_soLong *game)
{
	if (game->floor->img->img != NULL)
		mlx_destroy_image(game->frame->mlx, game->floor->img->img);
	if (game->wall->img->img != NULL)
		mlx_destroy_image(game->frame->mlx, game->wall->img->img);
	if (game->exit->img->img != NULL)
		mlx_destroy_image(game->frame->mlx, game->exit->img->img);
	if (game->player->img->img != NULL)
		mlx_destroy_image(game->frame->mlx, game->player->img->img);
	if (game->coll->img->img != NULL)
		mlx_destroy_image(game->frame->mlx, game->coll->img->img);
	return (0);
}

int	destroy_all_images(t_soLong *game)
{
	destroy_base(game);
	return (0);
}
