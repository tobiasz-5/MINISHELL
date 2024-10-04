/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:35:29 by acapobia          #+#    #+#             */
/*   Updated: 2023/11/08 20:52:20 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
	{
		start = s_len;
		len = 0;
	}
	if (start + len > s_len)
		len = s_len - start;
	str = ft_calloc(len + 1, sizeof (char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
/*
int main()
{
	char const *s = "ollare_the_gang";
	unsigned int start = 7;
	size_t len = 8;
	char *ptr = ft_substr(s, start, len);
	printf("%s", ptr);
	return 0;
}*/
