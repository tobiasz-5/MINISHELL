#include "miniheader.h"

static void	ft_handle_first_token(t_token_node **current, t_mini **mini)
{
	t_token_node	*t_ptr;
	int				size;
	int				i;
	
	i = 0;
	t_ptr = (*current);
	if (t_ptr->type != TOKEN_WORD)
		return ;
	size = 1;
	while (t_ptr->type == TOKEN_WORD &&
			ft_strncmp(t_ptr->next->token, "-", 1) == 0)
	{
		size++;
		t_ptr = t_ptr->next;
	}
	(*mini)->cmd = (char **)malloc((size + 1) * (sizeof(char *)));
	if (!(*mini)->cmd)
		return ;
	while (i < size)
	{
		(*mini)->cmd[i] = ft_strdup((*current)->token);
		(*current) = (*current)->next;
		i++;
	}
	(*mini)->cmd[i] = NULL;
}

int	ft_update_mini(t_mini **mini,t_token_node **current)
{
	t_token_node	*t_ptr;

	t_ptr = (*current);
	ft_handle_first_token(&t_ptr, &(*mini));//vede se il primo token è un comando e se si fa t_ptr = next;
	while (t_ptr)//TODO controlla il token finchè c'e una pipe o da NULL
	{
		if (t_ptr->type == TOKEN_WORD)
			ft_handle_pipe(&(*mini), (*current));//TODO
		else if (t_ptr->type == TOKEN_PIPE)
			ft_handle_word(&(*mini), (*current));//TODO
		else if (t_ptr->type == TOKEN_DOLLAR)
			ft_handle_dollar(&(*mini), (*current));//TODO
		else if (t_ptr->type == TOKEN_HEREDOC)
			ft_handle_heredoc(&(*mini), (*current));//TODO
		else if (t_ptr->type == TOKEN_REDIR_APPEND)
			ft_handle_re_append(&(*mini), (*current));//TODO
		else if (t_ptr->type == TOKEN_REDIR_IN)
			ft_handle_red_in(&(*mini), (*current));//TODO
		else if (t_ptr->type == TOKEN_REDIR_OUT)
			ft_handle_red_out(&(*mini), (*current));//TODO
		t_ptr = t_ptr->next;
		if (ft_check_token(t_ptr->type) == 1)//TODO
			break ;
	}
}

//non libera la pipe
void	ft_free_mini(t_mini **mini)
{
	if ((*mini)->redirect)
		free((*mini)->redirect);
	if ((*mini)->input)
		free((*mini)->input);
	if ((*mini)->cmd)
		free((*mini)->cmd);
	if ((*mini)->export)
		ft_free_exp(&(*mini)->export);
	if ((*mini)->env)
		ft_free_env(&(*mini)->env);
	free((*mini));
}

t_mini	ft_mini_init(char **env)
{
	t_mini	*mini;

	mini = NULL;
	mini = (t_mini *)malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->env = (t_env *)malloc(sizeof(t_env));
	if (!mini->env)
		return (NULL);
	mini->env->env_old = ft_copy_mtx(env);
	if (!mini->env->env_old)
		return (NULL);
	mini->input = NULL;
	mini->redirect = NULL;
	mini->cmd = NULL;
	mini->export = NULL;
	return (mini);
}
