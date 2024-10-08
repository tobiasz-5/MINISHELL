/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:57:42 by girindi           #+#    #+#             */
/*   Updated: 2024/10/07 15:40:54 by girindi          ###   ########.fr       */
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
