/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:24:18 by acapobia          #+#    #+#             */
/*   Updated: 2024/05/20 19:44:58 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_plus(char const *s1, char const *s2, size_t n)
{
	char	*ptr;
	size_t	len_1;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len_1 = ft_strlen(s1);
	ptr = (char *)malloc((len_1 + n) + 1);
	if (!ptr)
		return (NULL);
	while (s1[j])
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j] && j < n)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    if (!s1 && !s2)
        return NULL;
    if (!s1)
        return ft_strdup(s2);
    if (!s2)
        return ft_strdup(s1);

    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    char *str = malloc(len1 + len2 + 1);
    if (!str)
        return NULL;

    ft_memcpy(str, s1, len1);
    ft_memcpy(str + len1, s2, len2 + 1);  // +1 per includere il terminatore null
    return str;
}
