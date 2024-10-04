/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_character.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:00:40 by acapobia          #+#    #+#             */
/*   Updated: 2024/05/20 19:40:16 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_char(int c)
{
	char	a;

	a = (char)c;
	write(1, &a, 1);
	return (1);
}

int	put_str(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
	{
		write(1, &"(null)", 6);
		len += 6;
		return (len);
	}
	while (s[i])
		len += put_char(s[i++]);
	return (len);
}
