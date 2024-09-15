/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniheader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:47:52 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/15 18:06:00 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

#define MAX_TOKENS 100

#include "libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

typedef enum    e_token_type
{
    TOKEN_PIPE = 0,
    TOKEN_REDIR_APPEND = 1,
    TOKEN_HEREDOC = 2,
    TOKEN_REDIR_IN = 3,
    TOKEN_REDIR_OUT = 4,
    TOKEN_SINGLE_QUOTE = 5,
    TOKEN_DOUBLE_QUOTE = 6,
    TOKEN_DOLLAR = 7,
    TOKEN_WORD = 8,
}               t_token_type;

typedef struct  s_token_data
{
    char            *token;
    t_token_type    type;
}               t_token_data;

// tokenizer.c
const char *token_type_to_string(t_token_type type);
char **realloc_tokens(char **tokens, int *capacity);
int add_token(char **tokens, int *num_tokens, char *token);
int     count_tokens(char **words);
t_token_data    give_token_type(char *token);
t_token_data  *lexer(char *input);

// main.c
char **first_split(char *input);

// signals.c
void handle_sigint(int sig);
void handle_sigquit(int sig);
int	 handle_builtins(char *input, char *cmd);

#endif 

