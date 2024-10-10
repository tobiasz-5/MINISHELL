/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giulio <giulio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:14:18 by giulio            #+#    #+#             */
/*   Updated: 2024/10/10 18:51:35 by giulio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void	ft_pipe(t_mini **mini, t_token_node *current)
{
	while (current->next != NULL)
	{
		printf("current->token: %s\n", current->token);
		current = current->next;
		printf("%s", *(*mini)->cmd);
	}
}