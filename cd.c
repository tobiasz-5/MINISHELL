/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:40:38 by girindi           #+#    #+#             */
/*   Updated: 2024/10/15 11:57:09 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void	cd_back_dir(char *input);
void	cd_rel_path(char *input, int j);


static void find_oldpwd(t_mini *old)
{
	int	i;
	char *new_oldpwd;

	i = 0;
	new_oldpwd = ft_strjoin("OLDPWD=", getcwd(NULL, 0));
	if (!new_oldpwd)
		return ;
	while (old->env->env_new[i])
	{
		if (ft_strncmp(old->env->env_new[i], "OLDPWD=", 6) == 0)
		{
			free(old->env->env_new[i]);
			old->env->env_new[i] = new_oldpwd;
			break ;
		}
		i++;
	}
}

void	ft_cd(t_mini *old)
{
	int	i;

	i = 0;
	if (old->input[i] == '/')
	{
		if (chdir(&old->input[i]))
			printf("cd: no such file or directory: %s", &old->input[i]);
	}
	else
	{
		printf("INPUT: %s\n", &old->input[i]);
		// printf("1:%c\n2:%c", old->input[i + 1], old->input[i + 2]);
		find_oldpwd(old);
		if (old->input[i] == '.' && old->input[i + 1] == '.' && \
				(old->input[i + 2] == ' ' || old->input[i + 2] == '\0'))
		{
			ft_putstr_fd("cd ..\n", 1);
			cd_back_dir(old->input);}
		else
		{
			cd_rel_path(old->input, i);
		}
	}
	return ;
}

void	cd_back_dir(char *input)
{
	int		i;
	int		j;
	char	*dir;
	char	back_dir[50];

	i = 0;
	j = 0;
	if ((input[i + 2] != ' ' || input[i + 2] != '\0'))
		printf("cd: string not in pwd: ..");
	dir = getcwd(NULL, 0);
	while (dir[i])
		i++;
	while (i != 0 && dir[i] != '/')
		i--;
	while (j != i)
	{
		back_dir[j] = dir[j];
		j++;
	}
	back_dir[j] = '\0';
	chdir(back_dir);
	return ;
}

void	cd_rel_path(char *input, int j)
{
	char	*current_dir;
	char	new_dir[100];
	int		error;
	int		i;

	i = 0;
	error = j;
	current_dir = getcwd(NULL, 0);
	while (current_dir[i])
	{
		new_dir[i] = current_dir[i];
		i++;
	}
	new_dir[i++] = '/';
	while (input[j])
		new_dir[i++] = input[j++];
	new_dir[i] = '\0';
	if (chdir(new_dir))
		printf("cd: no such file or directory: %s", &input[error]);
}