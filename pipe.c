/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giulio <giulio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:14:18 by giulio            #+#    #+#             */
/*   Updated: 2024/10/16 19:16:13 by giulio           ###   ########.fr       */
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
void	ft_pipe(t_mini **mini, t_token_node *current)
{
	int fd[2];
	pid_t pid;
	int counter;
	
	counter = ft_lstcount(current);
	while (counter > 0)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd[1], 1);
			close(fd[0]);
			close(fd[1]);
			//execvp
			exit(0);
		}
		else
		{
			dup2(fd[0], 0);
			close(fd[0]);
			close(fd[1]);
			waitpid(pid, NULL, 0);
		}
		counter--;
	}
	printf("mini->cmd[0] = %s\n", (*mini)->cmd[0]);
}