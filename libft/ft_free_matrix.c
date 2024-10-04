/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:57:42 by acapobia          #+#    #+#             */
/*   Updated: 2024/05/20 22:02:37 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_mtx(char **matrix)
{
	char	**ptr;

	if (matrix == NULL)
		return ;
	ptr = matrix;
	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}
	free(matrix);
}
