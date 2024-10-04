/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:55:29 by acapobia          #+#    #+#             */
/*   Updated: 2023/10/31 14:40:03 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>
// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len] != '\0')
// 	{
// 		len++;
// 	}
// 	return (len);
// }
// char	*ft_strdup(const char *s)
// {
// 	char	*ptr;
// 	int		i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	ptr = (char *)malloc(i + 1);
// 	if (!ptr)
// 		return (NULL);
// 	ptr[i + 1] = '\0';
// 	while (i >= 0)
// 	{
// 		ptr[i] = s[i];
// 		i--;
// 	}
// 	return (ptr);
// }
static size_t	trim(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	if (set == NULL)
		return (ft_strdup(s1));
	while (s1[start] && trim(set, s1[start]))
		start++;
	while (end > start && trim(set, s1[end - 1]))
		end--;
	ptr = (char *)malloc((end - start) + 1);
	if (!ptr)
		return (NULL);
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}

// int main()
// {
//     char s1[] = "ciao";
//     char *trimmed_str = ft_strtrim(s1, "");

//     if (trimmed_str)
//     {
//         printf("Original string: \"%s\"\n", s1);
//         printf("Trimmed string: \"%s\"\n", trimmed_str);
//         free(trimmed_str);
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }
// }
