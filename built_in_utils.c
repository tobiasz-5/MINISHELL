/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:46:09 by negambar          #+#    #+#             */
/*   Updated: 2024/10/08 14:33:23 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

int	check_word(char *input, char *word, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < n && input[j] && word[i])
	{
		if (input[j] == '\'' || input[j] == '"')
		{
			j++;
		}
		if ((unsigned char)input[j] != (unsigned char)word[i])
			return ((unsigned char)input[j] - (unsigned char)word[i]);
		i++;
		j++;
	}
	if (i != n)
		return ((unsigned char)input[j] - (unsigned char)word[i]);
	return (0);
}
