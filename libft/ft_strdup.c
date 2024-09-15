/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:41:37 by mailinci          #+#    #+#             */
/*   Updated: 2024/05/28 11:46:40 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	int		len;
	char	*dup;

	len = ft_strlen(str) + 1;
	dup = NULL;
	if (!str)
		return (NULL);
	if (len == 0)
	{
		dup = (char *)malloc(1);
		if (!dup)
			return (NULL);
		dup[0] = '\0';
	}
	else
	{
		dup = (char *)malloc(len * sizeof(char));
		if (!dup)
			return (NULL);
		ft_strlcpy(dup, str, len);
		return (dup);
	}
	return (dup);
}
