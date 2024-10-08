/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:46:09 by girindi           #+#    #+#             */
/*   Updated: 2024/10/08 18:22:05 by girindi          ###   ########.fr       */
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
