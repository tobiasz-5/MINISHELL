/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:31:23 by girindi           #+#    #+#             */
/*   Updated: 2024/10/08 18:22:05 by girindi          ###   ########.fr       */
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
