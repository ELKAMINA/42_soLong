/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:11:29 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/03 16:11:39 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	invalid_char_inmap(t_soLong *game)
{
	write(1, "Error\n", 7);
	write(1, "Strange character in map\n", 26);
	free_crash_init(game);
	exit (0);
	return ;
}
