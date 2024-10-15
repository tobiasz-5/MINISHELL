/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:43:58 by negambar          #+#    #+#             */
/*   Updated: 2024/10/05 13:43:58 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void	ft_echo(char *input, char **cmd)
{
	int		flag_quotes;
	int		i;

	flag_quotes = closed_quote(input, ft_strlen(input));
	i = 0;
	while (input[i])
	{
		if (input[i] == ' ' || input[i] == '\t')
			i++;
		else if (input[i] == '"' && flag_quotes)
			i++;
		else if (input[i] == '"' && !flag_quotes)
			write(1, &input[i++], 1);
		else
			write(1, &input[i], 1);
		i++;
	}
	if (cmd[1] && ft_strcmp(cmd[1], "-n") == 0)
		printf("\n");
	return ;
}
