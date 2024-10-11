/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniheader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:20:53 by negambar          #+#    #+#             */
/*   Updated: 2024/09/27 12:20:53 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIHEADER_H
# define MINIHEADER_H

# define COLOR_RED "\033[31m"      // Colore rosso
# define BLUE "\033[1;34m"   
# define COLOR_ORANGE "\033[1;38;5;208m"  // Colore arancione
# define COLOR_RESET "\033[0m"     // Reset del colore

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_token_type
{
	TOKEN_PIPE,
	TOKEN_REDIR_APPEND,
	TOKEN_HEREDOC,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_SINGLE_QUOTE,
	TOKEN_DOUBLE_QUOTE,
	TOKEN_DOLLAR,
	TOKEN_WORD,
	TOKEN_UNKNOWN,
}	t_token_type;

typedef struct s_token_node
{
	char				*token;
	t_token_type		type;
	bool				single_quote;
	bool				double_quote;
	struct s_token_node	*next;
}	t_token_node;

typedef struct s_token_state
{
	char	*token_str;
	bool	single_quote;
	bool	double_quote;
}	t_token_state;

typedef struct s_env
{
	char	**env_old;
	char	**env_new;
}	t_env;

typedef struct s_exp
{
	char			*name;
	char			*value;//nome da selezionare
	struct s_exp	*next;
}	t_exp;

typedef struct s_red
{
	char			*simbol;
	struct s_red	*next;
}	t_red;
//TOUPGRADE
typedef struct s_mini
{
	int		exit_status;// per gestire $? ultimo exit
	bool 	pipe_check;
	bool	redirect;//init NULL
	char	*input;//init su quale input eseguire il comando
	char	**cmd;//init comando da eseguire
	t_exp	*export;//variabile d'ambiente $
	t_env	*env;
}	t_mini;
//cambiare strdup con ft_strdup //TODO
int				check_word(char *input, char *word, size_t n);
int				ft_check_cmd(char *cmd);
char			**ft_copy_cmd(t_token_node *current);
int				ft_check_token(t_token_node *t_ptr, t_token_node **start);
void			ft_handle_first_token(t_token_node **current, t_mini **mini);
void			ft_free_selected_mini(t_mini **mini);
void			ft_handle_heredoc(t_mini **mini, t_token_node *current);
void			ft_handle_append(t_mini **mini, t_token_node **current);
void			ft_handle_dollar(t_mini **mini, t_token_node *current);
void			ft_handle_red_in(t_mini **mini, t_token_node **current);
void			ft_handle_red_out(t_mini **mini, t_token_node **current);
void			ft_handle_world(t_mini **mini, t_token_node *current);
void			ft_free_mini(t_mini **mini);
int				ft_check_token(t_token_node *t_ptr, t_token_node **start);
void			ft_handle_first_token(t_token_node **current, t_mini **mini);
void			ft_update_mini(t_mini **mini,t_token_node **current);
char			**ft_copy_mtx(char **mtx);
void			ft_free_env(t_env **env);
void			ft_free_exp(t_exp **export);
t_mini			*ft_mini_init(char **env);
void			handle_sigint(int sig);
void			handle_sigquit(int sig);
void			handle_builtins(t_mini **mini);
void			ft_pwd();
void			ft_echo(char *input);
void			init_sign(void);
int				closed_quote(char *str, int i);
int				check_forn(char *input, int i);
const char		*token_type_to_string(t_token_type type);
t_token_node	*lexer(char *input);
void			process_input(char *input, t_mini **mini);
void			free_tokens(t_token_node *tokens);
t_token_type	determine_token_type(char *token_str);
t_token_node	*create_token_node(char *token_str);
t_token_node	*extract_token_str(char *input, int start, int end);
void			add_token_node(t_token_node **head, t_token_node **tail, \
				t_token_node *new_node);
int				skip_spaces(char *input, int i);
int				find_closing_quote(char *input, int i, char quote);
void			handle_unclosed_quote_error(t_token_state *state);
void			set_quote_flag(t_token_state *state, char quote);
int				handle_token_error(t_token_state *state);
void			init_lexer_vars(t_token_node **head, t_token_node **tail, \
				t_token_state *state, int *i, int *result);
int				process_next_token(char *input, int i, t_token_state *state, \
				t_token_node **head, t_token_node **tail);
int				append_to_temp_token_str(t_token_state *state, \
				char *temp_token);

#endif