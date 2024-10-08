/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:24:18 by girindi           #+#    #+#             */
/*   Updated: 2024/10/07 15:40:54 by girindi          ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len_1;
	size_t	len_2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	ptr = (char *)malloc((len_1 + len_2) + 1);
	if (!ptr)
		return (NULL);
	while (s1[j])
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
