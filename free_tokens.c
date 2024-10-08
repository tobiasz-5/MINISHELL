/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:31:23 by negambar          #+#    #+#             */
/*   Updated: 2024/10/08 14:32:28 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void	free_tokens(t_token_node *tokens)
{
	t_token_node	*temp;

	while (tokens)
	{
		temp = tokens; // Salva il nodo corrente per poterlo liberare
		tokens = tokens->next; // Passa al nodo successivo
		if (temp->token) // Se non è NULL libera la memoria
			free(temp->token);
		free (temp); // Libera il nodo corrente
	}
}
