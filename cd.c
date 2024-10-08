/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:40:38 by girindi           #+#    #+#             */
/*   Updated: 2024/10/08 19:25:20 by girindi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void	cd(char *input)
{
	char *current_dir;
	char new_dir[100];
	int i;
	int j;

	i = 0;
	j = 0;
	while (input[j] != 'd')
		j++;
	j += skip_spaces(&input[j], j); 
	if (input[j] == '/')
	{
		chdir(&input[j]);
		return ;
	}
	if (input[j] == '.' && input[j + 1] == '.')
	{
		cd_back_dir();
			return ;
	}
	// else 
	// {
	// 	cd_rel_path(input);
	// 	return ;
	// }
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
	chdir(new_dir);
}
void	cd_back_dir(void)
{
	int		i;
	int		j;
	char	*dir;
	char	back_dir[50];

	i = 0;
	j = 0;
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
}
