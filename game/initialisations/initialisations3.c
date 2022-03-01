/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisations3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:18:40 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/01 21:18:59 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_thing_player(t_soLong *game)
{
	game->player->pos_x = 0;
	game->player->pos_y = 0;
	game->player->total_nb = 0;
	game->player->total_moves = 0;
	game->player->nb_of_coll = 0;
}

void	init_thing_floor(t_soLong *game)
{
	game->floor->pos_x = 0;
	game->floor->pos_y = 0;
	game->floor->total_nb = 0;
	game->floor->total_moves = 0;
	game->floor->nb_of_coll = 0;
}

void	init_thing_coll(t_soLong *game)
{
	game->coll->pos_x = 0;
	game->coll->pos_y = 0;
	game->coll->total_nb = 0;
	game->coll->total_moves = 0;
	game->coll->nb_of_coll = 0;
}

void	init_thing_exit(t_soLong *game)
{
	game->exit->pos_x = 0;
	game->exit->pos_y = 0;
	game->exit->total_nb = 0;
	game->exit->total_moves = 0;
	game->exit->nb_of_coll = 0;
}

void	init_thing_wall(t_soLong *game)
{
	game->wall->pos_x = 0;
	game->wall->pos_y = 0;
	game->wall->total_nb = 0;
	game->wall->total_moves = 0;
	game->wall->nb_of_coll = 0;
}
