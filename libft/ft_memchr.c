/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:56:21 by girindi           #+#    #+#             */
/*   Updated: 2024/10/07 15:40:54 by girindi          ###   ########.fr       */
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
