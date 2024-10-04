/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:56:21 by acapobia          #+#    #+#             */
/*   Updated: 2023/10/29 11:38:21 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c_t_f;
	size_t			i;

	ptr = (unsigned char *)s;
	c_t_f = c;
	i = 0;
	if (n == 0)
		return (NULL);
	while (n > 0)
	{
		if (ptr[i] != c_t_f)
			i++;
		else
			return (&ptr[i]);
		n--;
	}
	return (NULL);
}
/*
int main()
{
	char *s = "ciao mondo";
	char *ptr = ft_memchr(s, 'm', 7);
	printf("%s", ptr);
	return 0;
}*/
