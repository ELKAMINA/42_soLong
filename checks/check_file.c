/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:25:39 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/02 12:51:09 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDWR);
	if (fd == -1)
	{
		write(1, "Error\n", 7);
		write(1, "Invalid file\n", 14);
		return (0);
	}
	else
		return (fd);
}

int	check_images(void)
{
	int	fd_o;
	int	fd_two;
	int	fd_th;
	int	fd_fo;
	int	fd_fiv;

	fd_o = open(COLL, O_RDONLY);
	fd_two = open(EXIT, O_RDONLY);
	fd_th = open(PLAYER, O_RDONLY);
	fd_fo = open(FLOOR, O_RDONLY);
	fd_fiv = open(WALL, O_RDONLY);
	if (fd_o < 0 || fd_two < 0 || fd_th < 0 || fd_fo < 0 || fd_fiv < 0)
	{
		write(1, "Error\nInvalid img\n", 19);
		return (1);
	}
	close(fd_o);
	close(fd_two);
	close(fd_th);
	close(fd_fo);
	close(fd_fiv);
	return (0);
}

void	check_if_empty(char *final)
{
	if (!final)
	{
		write(1, "Error\n", 7);
		write(1, "Empty map\n", 11);
		exit(0);
	}	
}

char	**get_stage(int fd)
{
	char			*buf;
	char			**map;
	static char		*final;

	buf = get_next_line(fd);
	check_if_empty(buf);
	while (buf)
	{
		final = ft_strjoin(final, buf);
		free(buf);
		buf = get_next_line(fd);
	}
	map = create_map(final, fd);
	return (map);
}
