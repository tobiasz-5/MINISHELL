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

int	check_word(char *input, char *word, size_t n)
{
	size_t i = 0;
	size_t j = 0;

	while (i < n && input[j] && word[i])
	{
		if (input[j] == '\'' || input[j] == '"')
		{
			j++;
			continue;
		}
		if ((unsigned char)input[j] != (unsigned char)word[i])
			return ((unsigned char)input[j] - (unsigned char)word[i]);
		i++;
		j++;
	}
	if (i != n)
		return (1);  // Il comando non corrisponde completamente
	if (input[j] != ' ' && input[j] != '\0')
		return (1);  // Il comando è seguito da qualcos'altro
	return (0);  // Comando riconosciuto correttamente
}

void	handle_builtins(t_mini	**mini)
{
	if (check_word((*mini)->cmd[0], "echo", 3) == 0)
		ft_echo((*mini)->input, (*mini)->cmd);//input stringa da stampare e cmd per vedere la flag
	// else if (check_word((*mini)->cmd[0], "cd", 1) == 0)
	// 	ft_cd((*mini));
	// else if (check_word((*mini)->cmd[0], "pwd", 2) == 0)
	// 	ft_pwd();//DONE
	// else if (check_word((*mini)->cmd[0], "export", 6) == 0)
	// 	ft_export(&(*mini));
	// else if (check_word((*mini)->cmd[0], "unset", 4) == 0)
	// 	ft_unset(&(*mini)->env);
	// else if (check_word((*mini)->cmd[0], "env", 2) == 0)
	// 	ft_env((*mini)->env);
}
