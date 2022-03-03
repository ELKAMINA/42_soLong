/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:30:52 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/03 16:12:25 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	checks(t_soLong *game)
{
	check_validity(game);
	check_validity_bis(game);
	check_walls(game);
}

void	count_initials(t_soLong *game)
{
	int			i;
	int			j;
	t_soLong	*game_c;

	i = 0;
	game_c = game;
	while (game_c->scene[i])
	{
		j = 0;
		while (game_c->scene[i][j])
		{
			if (game_c->scene[i][j] != '1' && game_c->scene[i][j] != 'C'
				&& game_c->scene[i][j] != 'P' && game_c->scene[i][j] != '0'
					&& game_c->scene[i][j] != 'E'
						&& game_c->scene[i][j] != '\n')
				invalid_char_inmap(game);
			increment(game_c, game_c->scene[i][j]);
			j++;
		}
		i++;
	}
	checks(game);
}

void	increment(t_soLong *game, char c)
{
	if (c == 'P')
		game->player->total_nb += 1;
	if (c == '0')
		game->floor->total_nb += 1;
	if (c == '1')
		game->wall->total_nb += 1;
	if (c == 'C')
		game->coll->total_nb += 1;
	if (c == 'E')
		game->exit->total_nb += 1;
}

void	check_validity(t_soLong *game)
{
	if (game->exit->total_nb < 1 || game->coll->total_nb < 1
		|| game->player->total_nb < 1)
	{
		write(1, "Error\n", 7);
		write(1, "At least 1 item, 1 collectible, 1 exit\n", 40);
		free_crash_init(game);
		exit(0);
		return ;
	}
}

void	check_walls(t_soLong *game)
{
	check_square(game);
	check_fence(game);
}
