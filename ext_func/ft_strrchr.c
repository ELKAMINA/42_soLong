/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:35:01 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/01 17:35:11 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strrchr(const char *s, int c)
{
	char			*sent;
	unsigned char	character;
	size_t			i;
	int				j;

	sent = (char *)s;
	character = (unsigned char)c;
	i = 0;
	j = -1;
	while (i <= ft_strlen((char *)s))
	{
		if (sent[i] != character)
			i++;
		else
		{
			j = i;
			i++;
		}
	}
	if (j == -1)
		return (1);
	return (j);
}
