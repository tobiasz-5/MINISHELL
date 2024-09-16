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

t_token_node *give_token_type(char *token_str)
{
    t_token_node *token_node;

    token_node = malloc(sizeof(t_token_node));
    if (!token_node)
        return (NULL);
    token_node->token = strdup(token_str);
    if (!token_node->token)
    {
        free(token_node);
        return (NULL);
    }
    token_node->type = determine_token_type(token_str);
    token_node->next = NULL;
    return (token_node);
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
        temp = tokens;
        tokens = tokens->next;
        free(temp->token);
        free(temp);
    }
}

void add_token_node(t_token_node **head, t_token_node **tail, t_token_node *new_node)
{
    if (!*head)
        *head = new_node;
    else
        (*tail)->next = new_node;
    *tail = new_node;
}

t_token_node *create_new_token_node(char *input, int start, int end)
{
    t_token_node *new_node;
    char         *token_str;

    new_node = NULL;
    token_str = strndup(input + start, end - start);
    if (!token_str)
        return (NULL);
    new_node = give_token_type(token_str);
    free(token_str);
    return (new_node);
}

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
        start = i;
        while (input[i] && input[i] != ' ')
            i++;
        if (i > start)
        {
            new_node = create_new_token_node(input, start, i);
            if (new_node)
                add_token_node(&head, &tail, new_node);
        }
    }
    return (head);
}

