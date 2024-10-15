#include "miniheader.h"
static void	ft_dollar_util(t_mini **mini, t_token_node *current)
{
	char	*tmp;
	char	*s;
	char	**false_s;
	t_exp	*ptr;
	size_t	i;

	i = 0;
	false_s = NULL;
	ptr = (*mini)->export;
	tmp = ft_strdup((const char *)(*mini)->input);
	s = ft_strdup((const char *)current->token);
	*false_s = s;
	if (!s || !false_s)
		return ;
	s++;
	while (s[i])
		i++;
	while (ft_strncmp((const char *)s, (const char *)ptr->name, i) != 0)
		ptr = ptr->next;
	(*mini)->input = ft_strjoin((const char *)tmp,(const char *)ptr->value);
	free(tmp);
	free((*false_s));
}

void	ft_handle_dollar(t_mini **mini, t_token_node *current)
{
	char	*tmp;
	char	*n;

	tmp = ft_strdup((const char *)(*mini)->input);
	if ((*mini)->input)
	free((*mini)->input);
	if (ft_strlen(current->token) == 1)
		(*mini)->input = ft_strjoin((const char *)tmp, "$ ");
	else if(ft_strlen(current->token) == 2 && current->token[1] == '?')
	{
		n = ft_itoa((*mini)->exit_status);
		(*mini)->input = ft_strjoin((const char *)tmp,(const char *) n);
		free(n);
	}
	else
		ft_dollar_util(&(*mini), current);
	free(tmp);
}
void	ft_handle_world(t_mini **mini, t_token_node *current)
{
	char	*tmp;
	printf("TOKEN :%s\n", current->token);
	printf("INPUT BEFORE :%s\n", (*mini)->input);
	tmp = NULL;
	if (current->token == NULL)
		return ;
	if ((*mini)->input != NULL)
	{
		tmp = ft_strjoin((const char *)(*mini)->input, " ");
		free((*mini)->input);
		(*mini)->input = NULL;		
		(*mini)->input = ft_strjoin(tmp, (const char *)current->token);
		free(tmp);
		printf("INPUT AFTER :%s\n", (*mini)->input);
	}
	else
	{
		(*mini)->input = ft_strdup((const char *)current->token);
		return ;
	}
}

void	ft_handle_red_out(t_mini **mini, t_token_node **current)
{
	int 			fd;

	if ((*mini)->redirect == false)
		(*mini)->redirect = true;
	(*current) = (*current)->next;
	fd = open((*current)->token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		printf("error '>'\n");
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	ft_handle_red_in(t_mini **mini, t_token_node **current)
{
	int 			fd;

	if ((*mini)->redirect == false)
		(*mini)->redirect = true;
	(*current) = (*current)->next;
	fd = open((*current)->token, O_RDONLY, 0644);
	if (fd < 0)
	{
		printf("error '<'\n");
		return ;
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}
