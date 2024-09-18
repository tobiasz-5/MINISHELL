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

// converte il tipo di token in una stringa per la stampa
const char *token_type_to_string(t_token_type type)
{
    switch (type)
    {
    case TOKEN_PIPE:         //      |
        return "PIPE";
    case TOKEN_REDIR_APPEND: //      >>
        return "REDIRECT_APPEND";
    case TOKEN_HEREDOC:      //      <<
        return "HEREDOC";
    case TOKEN_REDIR_IN:     //      <
        return "REDIRECT_IN";
    case TOKEN_REDIR_OUT:    //      >
        return "REDIRECT_OUT";
    case TOKEN_SINGLE_QUOTE: //      '
        return "SINGLE_QUOTE";
    case TOKEN_DOUBLE_QUOTE: //      "
        return "DOUBLE_QUOTE";
    case TOKEN_DOLLAR:       //      $
        return "DOLLAR";
    case TOKEN_WORD:         //      ls, wc, cat, etc.
        return "WORD";
    default:                 //      non dovrebbe mai accadere
        return "UNKNOWN";
    }
}

t_token_type determine_token_type(char *token_str)
{
    if (ft_strcmp(token_str, "|") == 0)
        return (TOKEN_PIPE);
    else if (ft_strcmp(token_str, ">>") == 0)
        return (TOKEN_REDIR_APPEND);
    else if (ft_strcmp(token_str, "<<") == 0)
        return (TOKEN_HEREDOC);
    else if (ft_strcmp(token_str, "<") == 0)
        return (TOKEN_REDIR_IN);
    else if (ft_strcmp(token_str, ">") == 0)
        return (TOKEN_REDIR_OUT);
    else if (ft_strcmp(token_str, "'") == 0)
        return (TOKEN_SINGLE_QUOTE);
    else if (ft_strcmp(token_str, "\"") == 0)
        return (TOKEN_DOUBLE_QUOTE);
    else if (ft_strcmp(token_str, "$") == 0)
        return (TOKEN_DOLLAR);
    else
        return (TOKEN_WORD);
}

void free_tokens(t_token_node *tokens)
{
    t_token_node *temp;

    while (tokens)
    {
        temp = tokens;              // Salva il nodo corrente per poterlo liberare
        tokens = tokens->next;      // Passa al nodo successivo
        if (temp->token)            // Se non è NULL libera la memoria
            free(temp->token);
        free(temp);                 // Libera il nodo corrente
    }
}

void add_token_node(t_token_node **head, t_token_node **tail, t_token_node *new_node)
{
    if (!*head)                     // Se la lista è vuota (head == NULL)
        *head = new_node;           // Il nuovo nodo diventa la testa
    else
        (*tail)->next = new_node;   // Collega l'ultimo nodo della lista al nuovo nodo
    *tail = new_node;               // Aggiorna il puntatore tail per farlo puntare al nuovo ultimo nodo
}


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

// Estrae il token dalla stringa di input e lo passa alla funzione create_token_node
t_token_node *extract_token_str(char *input, int start, int end)
{
    t_token_node *new_node;
    char         *token_str;

    new_node = NULL;
    token_str = strndup(input + start, end - start);    //Estrae la sottostringa dall'input
    if (!token_str)
        return (NULL);
    new_node = create_token_node(token_str);            //Crea un nuovo nodo con la sottostringa estratta
    free(token_str);                                    //Libera la sottostringa creata con strndup
    return (new_node);
}


// Divide la stringa di input in token e restituisce una lista concatenata di token
t_token_node *lexer(char *input)
{
    t_token_node *head;
    t_token_node *tail;
    t_token_node *new_node;
    
    int          i;
    int          start;
    head = NULL;
    tail = NULL;
    i = 0;
    while (input[i])
    {
        while (input[i] == ' ')
            i++;
        start = i;                              //  Salva la posizione iniziale del token
        while (input[i] && input[i] != ' ')     //  Trova la fine del token o della stringa
            i++;
        if (i > start)                          //  Se la lunghezza del token è maggiore di 0
        {
            new_node = extract_token_str(input, start, i);
            if (new_node)                        //  Se la creazione del nodo è andata a buon fine
                add_token_node(&head, &tail, new_node); //  Aggiungi il nodo alla lista
        }
    }
    return (head);
}

