/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:33:34 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/01 21:34:16 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_square(t_soLong *game)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (game->scene[i])
	{
		j = i + 1;
		while (game->scene[j])
		{
			if (ft_strlen(game->scene[i]) != ft_strlen(game->scene[j]))
			{
				write (1, "Error\n", 7);
				write (1, "It's not a rectangle\n", 22);
				free_crash_init(game);
				exit(0);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (i);
}

void	check_fence(t_soLong *game)
	{
	int	nb_lines;
	int	i;
	int	j;

	i = 1;
	j = 1;
	nb_lines = check_square(game);
	check_first_last_line(game, game->scene[0]);
	while (i != nb_lines - 1 && j != nb_lines - 1)
	{
		check_intermediate_lines(game, game->scene[j]);
		i++;
		j++;
	}
	check_first_last_line(game, game->scene[nb_lines - 1]);
	return ;
}

void	check_first_last_line(t_soLong *game, char *lineOne)
{
	int	i;

	i = 0;
	while (lineOne[i])
	{
		if (lineOne[i] != '1')
		{
			write (1, "Error\n", 7);
			write (1, "First or Last Line is not a wall\n", 34);
			free_crash_init(game);
			exit(0);
			return ;
		}
		i++;
	}
}

void	check_intermediate_lines(t_soLong *game, char *lineOne)
{
	if (lineOne[0] != '1' || lineOne[ft_strlen(lineOne) - 1] != '1')
	{
		write (1, "Error\n", 7);
		write (1, "There is no Wall\n", 18);
		free_crash_init(game);
		exit(0);
		return ;
	}
}
