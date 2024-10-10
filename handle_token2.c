#include "miniheader.h"

static void	ft_heredoc_delimiter(t_mini **mini)
{
	char	*tmp;

	tmp = ft_strdup((const char *)(*mini)->input);
	free((*mini)->input);
	(*mini)->input = ft_strjoin((const char *)tmp, "\n");
	free(tmp);
}

static void	ft_heredoc_util(t_mini **mini, char *string)
{
	char	*tmp;

	tmp = ft_strdup((const char *)(*mini)->input);
	free((*mini)->input);
	(*mini)->input = ft_strjoin((const char *)tmp, (const char *)string);
	free(tmp);
	tmp = ft_strdup((const char *)(*mini)->input);
	free((*mini)->input);
	(*mini)->input = ft_strjoin((const char *)tmp, "\n");
	free(tmp);
}
//aggiunge \n dopo invio e aggiunge \n anche dopo il delimiter
void	ft_handle_heredoc(t_mini **mini, t_token_node *current)
{
	char	*string;
	char	*del; //delimiter
	size_t	i;

	del = ft_strdup((const char *)current->next->token);
	if (!del)
	{
		printf("error delimiter");
		(*mini)->exit_status = -1;
		return ;
	}
	i = 0;
	while (del[i])
		i++;
	while (1)
	{
		string = readline("<");
		if (ft_strncmp((const char *)string, (const char *)del, i) == 0)
			break ;
		ft_heredoc_util(&(*mini), string);
		free(string);
	}
	ft_heredoc_delimiter(&(*mini));
	free(del);
	free(string);
}

void	ft_handle_append(t_mini **mini, t_token_node **current)
{
	int	fd;

	if ((*mini)->redirect == false)
		(*mini)->redirect = true;
	(*current) = (*current)->next;
	fd = open((*current)->token, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("error '>'\n");
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}