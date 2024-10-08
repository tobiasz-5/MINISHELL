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


int handle_builtins(char *input, char **env)
{
	if (check_word(input, "exit", 3) == 0)
	{
		return (1);
	}
	else if (check_word(input, "echo", 3) == 0)
	{
		ft_echo(input);
		return (0);
	}
	else if (check_word(input, "pwd", 2) == 0)
	{
		ft_pwd();
		return (0);
	}
	else if (check_word(input, "env", 2) == 0)
	{
			get_env(env);
			return (0);
	}
	else if (ft_strncmp(input, "cd", 1) == 0)
	{
			cd(input);
			return (0);
	}
	return (0);
}
