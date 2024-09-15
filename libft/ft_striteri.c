/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:56:43 by mailinci          #+#    #+#             */
/*   Updated: 2024/03/10 16:07:58 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*fx)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		(*fx)(i, &str[i]);
		i++;
	}
	str[i] = '\0';
}
