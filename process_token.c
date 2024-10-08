/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:53:41 by girindi           #+#    #+#             */
/*   Updated: 2024/10/08 18:22:05 by girindi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void	create_real_token(t_token_state *state, t_token_node **head, \
							t_token_node **tail)
{
	t_token_node	*new_node;

	new_node = create_token_node(state->token_str);
	//crea effettivamente il nodo
	if (new_node) //se il nodo e' stato creato correttamente
	{
		new_node->single_quote = state->single_quote;//imposta struttura token
		new_node->double_quote = state->double_quote;
		add_token_node(head, tail, new_node); //aggiunge il nodo alla lista
	}
	free(state->token_str);
	state->token_str = NULL; //per i puntatori dangling
	state->single_quote = false; //resetta i booleani
	state->double_quote = false;
}

/* Le due funzioni: process_quoted_token e process_normal_token 
	lavorano insieme per creare un token.
Se ho un input come: abc'  cd'e
abc: verra' processato da process_normal_token.
'  cd': verra' processato da process_quoted_token
e: verra' processato da process_normal_token.
il tutto viene concatenato in un unico token.
alla fine il token sara': abc  cde
come avviene in bash ~/PROMPTBASH$ abc'  cd'e
abc  cde: command not found   --> omg O_O :)
*/
int	process_quoted_token(char *input, int i, \
char quote, t_token_state *state)
{
	int		start;
	int		end;
	char	*temp_token;
	int		result;

	i++; //salta la virgoletta di apertura
	start = i;
	end = find_closing_quote(input, i, quote);
	//trova la posizione della virgoletta di chiusura, se no ritorna -1
	if (end == -1)
	{
		handle_unclosed_quote_error(state);
		return (-1);
	}
	temp_token = strndup(input + start, end - start);
	//estrae il contenuto tra le virgolette
	if (!temp_token)
		return (-1);
	result = append_to_temp_token_str(state, temp_token);
	//aggiunge il contenuto al token corrente
	free(temp_token);
	if (result == -1)
		return (-1);
	set_quote_flag(state, quote);
	i = end + 1;
	//aggiorna l'indice per continuare dopo la virgoletta di chiusura
	return (i);
	//ritorna la posizione del prossimo carattere utile
}

int	process_normal_token(char *input, int i, t_token_state *state)
{
	int		start;
	char	*new_str;
	char	*temp_token;
	//variabile temporanea per memorizzare il token
	start = i;
	while (input[i] && input[i] != ' ' && input[i] != '\'' && input[i] != '"')
		i++;
	temp_token = strndup(input + start, i - start);
	if (!temp_token)
		return (-1);
	new_str = ft_strjoin(state->token_str, temp_token);
	//concatena il nuovo segmento di token al token corrente
	free(state->token_str);
	free(temp_token);
	if (!new_str)
		return (-1);
	state->token_str = new_str;
	return (i); //ritorna la posizione del prossimo carattere utile
}

int	process_token(char *input, int i, t_token_state *state)
{
	char	quote; // variabile per tenere traccia del tipo di quote
	//se il carattere corrente è una virgoletta, 
	// chiama process_quoted_token, altrimenti, process_normal_token.
	if (input[i] == '\'' || input[i] == '"')
	{
		quote = input[i];
		return (process_quoted_token(input, i, quote, state));
	}
	else
		return (process_normal_token(input, i, state));
}

int	process_next_token(char *input, int i, t_token_state *state, \
						t_token_node **head, t_token_node **tail)
{
	while (input[i] && input[i] != ' ')
	{
		i = process_token(input, i, state);
		if (i == -1)
			return (handle_token_error(state));
	}
	if (state->token_str) //se il campo e' stato riempito
		create_real_token(state, head, tail);
	//crea un nuovo nodo con il token_str giusto e lo stato delle quotes
	return (i); //ritorna la posizione del prossimo carattere utile
}
