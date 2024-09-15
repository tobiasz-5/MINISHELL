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

// rialloca memoria per l'array di token quando la capacità attuale è piena
char **realloc_tokens(char **tokens, int *capacity) 
{
    *capacity *= 2;
    tokens = realloc(tokens, *capacity * sizeof(char *));
    if (!tokens) 
    {
        perror("realloc");
        return NULL;
    }
    return tokens;
}

int add_token(char **tokens, int *num_tokens, char *token)
{
    tokens[*num_tokens] = strdup(token);
    if (!tokens[*num_tokens]) {
        perror("strdup");
        return -1;
    }
    (*num_tokens)++;
    return 0;
}

int     count_tokens(char **words)
{
    int     i;

    i = 0;
    while (words[i])
        i++;
    return (i);
}

// determina il tipo di un token in base al suo contenuto
t_token_data    give_token_type(char *token)
{
    t_token_data    token_data;

    token_data.token = strdup(token);
    if(strcmp(token, "|") == 0)
        token_data.type = TOKEN_PIPE;
    else if(strcmp(token, ">>") == 0)
        token_data.type = TOKEN_REDIR_APPEND;
    else if(strcmp(token, "<<") == 0)
        token_data.type = TOKEN_HEREDOC;
    else if(strcmp(token, "<") == 0)
        token_data.type = TOKEN_REDIR_IN;
    else if(strcmp(token, ">") == 0)
        token_data.type = TOKEN_REDIR_OUT;
    else if(strcmp(token, "'") == 0)
        token_data.type = TOKEN_SINGLE_QUOTE;
    else if(strcmp(token, "\"") == 0)
        token_data.type = TOKEN_DOUBLE_QUOTE;
    else if(strcmp(token, "$") == 0)
        token_data.type = TOKEN_DOLLAR;
    else
        token_data.type = TOKEN_WORD;
    return (token_data);
}

// analizza l'input e lo converte in una lista di token
t_token_data  *lexer(char *input)
{
    char            **words;
    t_token_data    *tokens;
    int             num_tokens;
    int             i;

    words = first_split(input);
    if (!words)
        return NULL;
    num_tokens = count_tokens(words);
    tokens = malloc(sizeof(t_token_data) * (num_tokens + 1));
    if (!tokens)
        return NULL;
    i = 0;
    num_tokens = 0;
    while(words[i])
    {
        tokens[num_tokens] = give_token_type(words[i]);
        num_tokens++;
        free(words[i]);
        i++;
    }
    free(words);
    tokens[num_tokens].token = NULL;
    return (tokens); 
}