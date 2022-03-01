/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:42:44 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/01 21:42:55 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	int			fd;
	t_soLong	game;

	fd = check_create(argc, argv);
	if (fd == 0)
		return (0);
	init_struct_game(&game, fd);
	verif_scene(&game);
	get_background(&game);
	get_width_height(&game);
}
