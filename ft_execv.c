#include "miniheader.h"

char	**ft_mtx_execv(char *input, char **cmd)
{
	char	**mtx;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mtx = NULL;
	while (cmd[i] != NULL)
		i++;
	mtx = (char **)malloc((i + 1) * sizeof(char *));
	if (!mtx)
		return (NULL);
	while (j < i)
	{
		mtx[j] = ft_strdup(cmd[j]);
		j++;
	}
	mtx[j] = ft_strdup(input);
	j++;
	mtx[j] = NULL;
	return (mtx);
}

static char	*ft_path(char *cmd)
{
	char	*path;

	path = ft_strjoin("/usr/bin/", (const char *)cmd);
	if (!path)
		return (NULL);
	if (access(path, X_OK) == -1)
	{
		ft_printf("\nERRORE PATH\n");
	}
	return (path);
}

void	ft_execv(t_mini **mini)
{
	char	**mtx_cmd;
	char	*path;
	int		pid;
	int		status;

	mtx_cmd = NULL;
	path = ft_path((*mini)->cmd[0]);
	if (!path)
		return ;
	mtx_cmd = ft_mtx_execv((*mini)->input, (*mini)->cmd);
	if (!mtx_cmd)
		return ;
	pid = fork();
	if (pid == 0)
	{
		if ((*mini)->env->env_new == NULL)
			execve(path, mtx_cmd, (*mini)->env->env_old);
		else
			execve(path, mtx_cmd, (*mini)->env->env_new);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		(*mini)->exit_status = pid;
	}
	else
		perror("error fork\n");
}
