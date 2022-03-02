/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:36:47 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/01 21:36:49 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	freeing(char **game)
{
	int	i;

	i = 0;
	while (game[i])
	{
		free(game[i]);
		game[i] = NULL;
		i++;
	}
	free(game);
	game = NULL;
}

void	free_crash_init(t_soLong *game)
{
	free(game->floor->img);
	free(game->wall->img);
	free(game->player->img);
	free(game->exit->img);
	free(game->coll->img);
	free(game->frame->mlx);
	free(game->frame);
	free(game->floor);
	free(game->wall);
	free(game->player);
	free(game->exit);
	free(game->coll);
	freeing(game->scene);
}

void exit_return()
{
	exit (0);
	return ;
}

