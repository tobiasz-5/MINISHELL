/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giulio <giulio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:14:18 by giulio            #+#    #+#             */
/*   Updated: 2024/10/17 17:38:57 by giulio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

static void count_cmd_pipe(t_token_node *current, t_mini *mini)
{
	mini->pipe_cmd = 0;
	while (current != NULL)
	{
		if (current->type == TOKEN_WORD && current->next->type == TOKEN_WORD)
		{
			mini->pipe_cmd++;
			current = current->next;
		}
		else
			mini->pipe_cmd++;
		current = current->next;
	}
}


static void update_cmd_pipe(t_mini *mini, t_token_node *current)
{
	int i;
	char *tmp;
	i = 0;
	mini->pipe_cmd++;
	mini->cmd = (char **)malloc((mini->pipe_cmd) * sizeof(char *));
	if (!mini->cmd)
		return ;
	while (current != NULL)
	{
		if (current->type == TOKEN_WORD && current->next->type == TOKEN_WORD)
		{
			tmp = ft_strjoin(current->token, " ");
			mini->cmd[i++] = ft_strjoin(tmp, current->next->token);
			current = current->next;
		}
		else if (current->type == TOKEN_WORD)
			mini->cmd[i++] = ft_strdup(current->token);
		current = current->next;
	}
	mini->cmd[i] = NULL;
}

void	init_pipe(t_mini *mini, t_token_node *current)
{
	int count;
	
	count = 0;
	if (mini->cmd != NULL)
	{
		ft_free_mtx(mini->cmd);
		mini->cmd = NULL;
	}
	count_cmd_pipe(current, mini);
	update_cmd_pipe(mini, current);
	while (mini->cmd[count] != NULL)
	{
		printf("cmd[%d]: %s\n", count, mini->cmd[count]);
		count++;
	}
}

static char	*find_path(char **envp, char *cmd)
{
	int		i;
	char	**paths;
	char	*path;
	char	*tmp;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	paths = ft_split(envp[i], ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	// free_matrix(paths);
	printf("Command not found\n");
	return (NULL);
}

static void	execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = find_path(envp, cmd[0]);
	if (!path)
	{
		// free_matrix(cmd);
		printf("Error finding path\n");
	}
	if (execve(path, cmd, envp) == -1)
	{
		printf("Error executing command\n");
	}
	printf("executing command\n");
	return ;
}

static void child_process(t_token_node *current, int prev_fd, int *fd, bool redirect, t_mini *mini, int cmd)
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
		execute(mini->cmd[cmd], mini->env->env_new);
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
		execute(current->token, mini->env->env_old);
		close(fd[1]);
		close(fd[0]);
		close(prev_fd);
	}
}
void	ft_pipe(t_mini *mini, t_token_node *current)
{
	int i;
	int	fd[2];
	pid_t	pid;
	int	prev_fd;
	// int status;
	
	i = 0;
	prev_fd = -1;
	while (i < mini->pipe_cmd)
	{
		if (i < mini->pipe_cmd - 1)
		{
			if (pipe(fd) == -1)
				printf("ERRORE PIPE\n"); //to_modify
		}	
		pid = fork();
		if (pid < 0)
			printf("ERRORE FORK\n");//to_modify
		if (pid == 0)
			child_process(current, prev_fd, fd, mini->redirect, mini, i);
		else
		{
			if (prev_fd != -1)
				close(prev_fd);
			// waitpid(pid, &status, 0);
			wait(NULL);
			mini->exit_status = pid;
		}
		prev_fd = fd[0];
		i++;
	}
}