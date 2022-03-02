/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_mngt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:13:18 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/01 18:13:21 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	get_interm_scene(t_soLong *game, int x, int y, int co)
{
	game->scene[y][x] = '0';
	game->player->total_moves++;
	ft_printf("\r --- %d ---", game->player->total_moves);
	if (co == 1)
		game->player->nb_of_coll++;
	get_ze_game(game);
}

void	get_end_scene(t_soLong *game, int x, int y)
{
	game->scene[y][x] = '0';
	game->player->total_moves++;
	ft_printf("\r -- %d ---", game->player->total_moves);
	quit_game(game);
}
