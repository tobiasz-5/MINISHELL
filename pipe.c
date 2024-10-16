/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giulio <giulio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:14:18 by giulio            #+#    #+#             */
/*   Updated: 2024/10/16 21:53:28 by giulio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"


static int	ft_lstcount(t_token_node *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

static void child_process(t_token_node *current, int prev_fd, int *fd, bool redirect, t_mini *mini)
{
	int	filein;
	int fileout;
	
	if (prev_fd == -1)
	{
		if (redirect == true)
		{
			filein = open(current->token, 0777);
			dup2(filein, STDIN_FILENO);
			close(filein);
			close(fd[1]);
		}
	
		else
			dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		ft_execv(&mini);
		close(fd[1]);
		close(fd[0]);
	}
	else
	{
		dup2(prev_fd, STDIN_FILENO);
		if (current->next != NULL)
			dup2(fd[1], STDOUT_FILENO);
		else if (redirect == true)
		{
			fileout = open(current->token, O_CREAT | O_WRONLY | O_TRUNC);
			dup2(fileout, STDOUT_FILENO);
			close(fileout);
		}
		ft_execv(&mini);
		close(fd[1]);
		close(fd[0]);
		close(prev_fd);
	}
}
void	ft_pipe(t_mini *mini, t_token_node *current)
{
	int	counter;
	int i;
	int	fd[2];
	pid_t	pid;
	int	prev_fd;
	
	i = 0;
	prev_fd = -1;
	counter = ft_lstcount(current);
	while (i < counter)
	{
		if (i < counter - 1)
		{
			if (pipe(fd) == -1)
				printf("ERRORE PIPE\n"); //to_modify
		}	
		pid = fork();
		if (pid < 0)
			printf("ERRORE FORK\n");//to_modify
		if (pid == 0)
			child_process(current, prev_fd, fd, mini->redirect, mini);
		else
		{
			if (prev_fd != -1)
				close(prev_fd);
			waitpid(pid, NULL, 0);
			mini->exit_status = pid;
		}
		prev_fd = fd[0];
		i++;
	}
}