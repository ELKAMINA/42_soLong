/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:16:26 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/01 21:16:32 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_struct_game(t_soLong *game, int fd)
{
	game->scene = get_stage(fd);
	init_struct_frame(game);
	init_struct_thing(game);
}

void	init_struct_frame(t_soLong *game)
{
	game->frame = malloc(sizeof(t_frame));
	game->frame->mlx = 0;
	game->frame->win = 0;
	game->frame->win_w = 0;
	game->frame->win_h = 0;
}

void	init_struct_img(t_soLong *game)
{
	game->player->img = malloc(sizeof(t_img));
	if (!game->player->img)
		exit_return();
	game->wall->img = malloc(sizeof(t_img));
	if (!game->wall->img)
		exit_return();
	game->coll->img = malloc(sizeof(t_img));
	if (!game->coll->img)
		exit_return();
	game->exit->img = malloc(sizeof(t_img));
	if (!game->exit->img)
		exit_return();
	game->floor->img = malloc(sizeof(t_img));
	if (!game->floor->img)
		exit_return();
	init_player(game);
	init_wall(game);
	init_coll(game);
	init_exit(game);
	init_floor(game);
}

void	init_struct_thing(t_soLong *game)
{
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
