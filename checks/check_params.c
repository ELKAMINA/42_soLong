/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:28:11 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/01 21:29:08 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_create(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "Error\n", 7);
		write(1, "Wrong number of Args\n", 22);
		return (0);
	}
	else
		return (check_name_arg(argv));
}

int	check_name_arg(char *argv[])
{
	size_t	len;

	len = ft_strlen(argv[1]);
	if (ft_strnstr(argv[1], ".ber", len) == 0
		|| argv[1][ft_strrchr(argv[1], '.') - 1] == '\0' ||
			argv[1][ft_strrchr(argv[1], '.') - 1] == '/')
	{
		write(1, "Error\n", 7);
		write(1, "Wrong format in args\n", 22);
		return (0);
	}
	else
		return (check_file(argv[1]));
}
