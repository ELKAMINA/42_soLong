/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:34:40 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/01 17:34:48 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hays;

	i = 0;
	j = 0;
	hays = (char *)haystack;
	if (needle[0] == '\0' || needle == NULL)
		return (3);
	while (hays[i] != '\0' && i < len)
	{
		j = 0;
		while (hays[i] == needle[j] && hays != (void *)0
			&& needle[j] != '\0' && i < len)
		{
			i ++;
			j ++;
		}
		if (needle[j] == '\0' && i - j < len)
			return (1);
		i -= j;
		i++;
	}
	return (0);
}
