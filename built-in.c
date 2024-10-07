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


int handle_builtins(char *input, t_mini *old)
{
	while (*input == ' ')
		input++;
	if (ft_strncmp(input, "exit", 4) == 0)
	{
		return (1);
	}
	else if (ft_strncmp(input, "echo", 3) == 0)
	{
			ft_echo(input);
			return (0);
	}
	else if (ft_strncmp(input, "pwd", 3) == 0)
	{
			ft_pwd();
			return (0);
	}
	else if (ft_strncmp(input, "env", 3) == 0)
	{
			get_env(old);
	}
	return (0);
}
