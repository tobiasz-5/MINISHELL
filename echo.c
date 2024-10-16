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

int ft_skip(char *input, char *echo)
{
	int i;

	i = 0;
	while ((input[i] == echo[i]) || (input[i] == ' '))
		i++;
	return (i);
}

void	ft_echo(char *input, char **cmd)
{
	int		flag_quotes;
	int		i;

	i = 0;
	i = ft_skip(input, "echo ");
	flag_quotes = closed_quote(input, ft_strlen(input));
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
	if (!cmd[1])
		write(1, "\n", 1);
	return ;
}
