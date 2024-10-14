/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:40:15 by negambar          #+#    #+#             */
/*   Updated: 2024/09/15 18:05:55 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

int	handle_builtins(t_mini	**mini)
{
	while (*(*mini)->input == ' ')
		(*mini)->input++;
	printf("handle_builtins\n");
	printf("mini->cmd[0] = %s\n", (*mini)->cmd[0]);
	if (ft_strncmp((*mini)->input, "echo", 3) == 0)
	{
		ft_echo((*mini)->input);
		return (0);
	}
	else if (ft_strncmp((*mini)->input, "pwd", 3) == 0)
	{
		ft_pwd();
		return (0);
	}
	return (0);
}
