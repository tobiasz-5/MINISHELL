/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_analyze_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:08:27 by girindi           #+#    #+#             */
/*   Updated: 2024/10/08 18:22:05 by girindi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

int	find_closing_quote(char *input, int i, char quote)
{
	while (input[i] && input[i] != quote)
		i++;
	if (!input[i]) // Closing quote not found
		return (-1);
	return (i);
}

void	handle_unclosed_quote_error(t_token_state *state)
{
	fprintf(stderr, COLOR_RED "Error: Unclose	 quote detected\n" COLOR_RESET);
	if (state->token_str) // se e' stato creato un token lo deallochiamo
	{
		free(state->token_str);
		state->token_str = NULL;
		// per puntatori che puntano a  memoria che non serve piu'
	}
}

void	set_quote_flag(t_token_state *state, char quote)
{
	if (quote == '\'')
		state->single_quote = true;
	else if (quote == '"')
		state->double_quote = true;
}

int	handle_token_error(t_token_state *state)
{
	if (state->token_str)
	{
		free(state->token_str);
		state->token_str = NULL;
	}
	return (-1);
}

void	init_lexer_vars(t_token_node **head, t_token_node **tail, \
					t_token_state *state, int *i, int *result)
{
	*head = NULL;
	*tail = NULL;
	state->token_str = NULL;
	state->single_quote = false;
	state->double_quote = false;
	*i = 0;
	*result = 0;
}
