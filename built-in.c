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

int	check_word(char *input, char *word, int n)
{
	int i = 0;
	int j = 0;

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
	printf("handle_builtins\n");
	if (check_word((*mini)->cmd[0], "echo", 4) == 0)
		ft_echo((*mini)->input, (*mini)->cmd);
	else if (check_word((*mini)->cmd[0], "cd", 2) == 0)
		ft_cd((*mini));
	else if (check_word((*mini)->cmd[0], "pwd", 3) == 0)
		ft_pwd();//DONE
	else if (check_word((*mini)->cmd[0], "env", 3) == 0)
		{printf("ENV\n");get_env(*mini);}
	/* else if (check_word((*mini)->cmd, "export", 6) == 0)
		ft_export(&(*mini));
	else if (check_word((*mini)->cmd, "unset", 4) == 0)
		ft_unset(&(*mini)->env);  */
}
