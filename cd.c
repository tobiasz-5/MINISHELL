/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:40:38 by girindi           #+#    #+#             */
/*   Updated: 2024/10/09 16:41:26 by girindi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void	cd(char *input)
{
	int i;

	i = 0;
	while (input[i] != 'd')
		i++;
	i += skip_spaces(&input[i], i); 
	if (input[i] == '/')
	{
		if (chdir(&input[i]))
			ft_printf("cd: no such file or directory: %s", &input[i]);
	}
	else if (input[i] == '.' && input[i + 1] == '.' && 
			(input[i + 2] == ' ' || input[i + 2] == '\0'))
		cd_back_dir(&input[i]);
	else
		cd_rel_path(input, i);
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
		ft_printf("cd: string not in pwd: ..");
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

void cd_rel_path(char *input, int j)
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
		ft_printf("cd: no such file or directory: %s", &input[error]);
}