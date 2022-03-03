/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:52:16 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/03 11:52:18 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	double_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '\n')
		i++;
	while (s[i] && s[i + 1])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	invalid_map_msg(char *final)
{
	write(1, "Error\n", 7);
	write(1, "Invalid map\n", 13);
	free(final);
	exit(0);
}

char	**create_map(char *final, int fd)
{
	char	**map;

	map = NULL;
	if (final)
	{
		if (double_newline(final) == 1)
			invalid_map_msg(final);
		else
		{
			map = ft_split(final, '\n');
			free(final);
			close(fd);
		}
		return (map);
	}
	else
	{
		invalid_map_msg(final);
		return (map);
	}
}
