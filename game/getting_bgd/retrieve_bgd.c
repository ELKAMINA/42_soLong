/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_bgd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:07:21 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/02 18:07:08 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	get_width_height(t_soLong *game)
{
	int	wi_g;
	int	hei_g;

	hei_g = check_square(game);
	wi_g = ft_strlen(game->scene[0]);
	game->frame->win_w = wi_g * IMG_SIZE;
	game->frame->win_h = hei_g * IMG_SIZE;
}

int	get_mlx_win(t_soLong *game)
{
	game->frame->mlx = mlx_init();
	if (game->frame->mlx == NULL)
	{
		write(1, "Error\n", 7);
		write(1, "Failed to init MLX\n", 20);
		free_crash_init(game);
		exit (0);
		return (0);
	}
	get_width_height(game);
	game->frame->win = mlx_new_window(game->frame->mlx, game->frame->win_w,
			game->frame->win_h, "42 Wimbledon");
	return (1);
}

void	get_game_base(t_soLong *game)
{
	init_decor(game);
	get_ze_game(game);
}

void	get_background(t_soLong *game)
{
	get_mlx_win(game);
	get_game_base(game);
}
