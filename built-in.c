/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:40:15 by girindi           #+#    #+#             */
/*   Updated: 2024/10/11 12:34:20 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

int	handle_builtins(char *input, t_mini *old)
{
	if (check_word(input, "exit", 3) == 0)
		return (1);
	else if (check_word(input, "echo", 3) == 0)
		ft_echo(input);
	else if (check_word(input, "pwd", 2) == 0)
		ft_pwd();
	else if (check_word(input, "env", 2) == 0)
		get_env(old);
	else if (check_word(input, "cd", 1) == 0)
		cd(input, old);
	else if (check_word(input, "export", 6) == 0)
		ft_exp(old, input);
	return (0);
}
