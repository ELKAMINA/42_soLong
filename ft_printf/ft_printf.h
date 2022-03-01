/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:38:41 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/01 21:38:43 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int				ft_putnbr_counting(int n);
int				ft_putchar_counting(char s);
int				ft_putnbr_base(unsigned long long n, char *s);
int				ft_putstr_counting(char *s);
int				ft_printf(const char	*fmt, ...);

#endif
