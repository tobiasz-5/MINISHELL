/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:21:56 by girindi           #+#    #+#             */
/*   Updated: 2024/10/07 15:40:54 by girindi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include<stdio.h>*/
char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)str + i);
	return (NULL);
}

/*int main()
{
	const char s[]="bonjour";
	char  *occurrence = ft_strchr(s, 's');
	printf("%s", occurrence);
}*/
