/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:38:06 by negambar          #+#    #+#             */
/*   Updated: 2024/10/05 13:41:07 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	unsigned char		*src_ptr;

	dest_ptr = (unsigned char *) dest;
	src_ptr = (unsigned char *) src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*dest_ptr = *src_ptr;
		if (dest != NULL)
			dest_ptr++;
		if (src != NULL)
			src_ptr++;
		n--;
	}
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = strlen(s1);
	len2 = strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2 + 1); // +1 per includere il terminatore null
	return (str);
}

int	skip_spaces(char *input, int i)
{
	while (input[i] == ' ')
		i++;
	return (i);
}
