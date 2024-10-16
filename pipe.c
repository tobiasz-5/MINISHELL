/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giulio <giulio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:14:18 by giulio            #+#    #+#             */
/*   Updated: 2024/10/15 18:27:52 by giulio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

int counter_token(t_token_node *current, t_token_node **tmp)
{
	int i;

	i = 0;
	while ((*tmp) != NULL)
	{
		i++;
		(*tmp) = (*tmp)->next;
	}
	return (i);
}

void	ft_pipe(t_mini **mini, t_token_node *current)
{
	int fd[2];
	pid_t pid;
	t_token_node *tmp;
	int counter;
	
	counter = 0;
	tmp = current;
	counter = counter_token(current, &tmp);
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
	
}