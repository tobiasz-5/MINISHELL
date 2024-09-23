/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:49:56 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/15 15:59:13 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

//  Crea un nuovo nodo, copia il token stringa, determina il tipo e restituisce il puntatore al nodo creato
t_token_node *create_token_node(char *token_str)
{
    t_token_node *token_node;

    token_node = malloc(sizeof(t_token_node));
    if (!token_node)
        return (NULL);
    token_node->token = strdup(token_str);              //Copia la stringa token nel campo token del nodo
    if (!token_node->token)
    {
        free(token_node);
        return (NULL);
    }
    token_node->type = determine_token_type(token_str); //Determina il tipo del token
    token_node->next = NULL;                            //Imposta il campo next a NULL per garantire che il nodo sia l'ultimo della lista
    return (token_node);
}

t_token_node *lexer(char *input)
{
    t_token_node *head;
    t_token_node *tail;         
    t_token_state state;
    int i;
    int result;

    init_lexer_vars(&head, &tail, &state, &i, &result);
    while (input[i])
    {
        i = skip_spaces(input, i);                                      // Salta gli spazi e salva la posizione del primo carattere utile ad ogni ciclo
        result = process_next_token(input, i, &state, &head, &tail);    // Processa il token successivo e salva la posizione del prossimo carattere utile
        if (result == -1)
        {
            if (head)                                            // Se c' e stato un errore ma la lista e' stata iniziata libera i nodi
                free_tokens(head);
            return NULL;
        }
        i = result; 
        if (input[i] == ' ')
            i++;
    }
    return head;
}