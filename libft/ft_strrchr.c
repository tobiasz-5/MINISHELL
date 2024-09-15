/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:20:55 by mailinci          #+#    #+#             */
/*   Updated: 2024/03/10 16:09:08 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			p = ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		p = ((char *)&str[i]);
	return (p);
}
