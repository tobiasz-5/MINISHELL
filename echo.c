/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:11:43 by marvin            #+#    #+#             */
/*   Updated: 2024/09/18 15:11:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

static int	skip_white(char *input, int flag, int i)
{
	int	j;

	j = 0;
	i = skip_spaces(input, i);
	j = i + 2;
	if (flag)
		i = skip_spaces(input, j);
	return (i);
}

static int	skip_echo(char *echo, char *input, int i)
{
	while (echo[i])
	{
		if (input[i] != echo[i])
			return (-99999);
		i++;
	}
	if (input[i] != ' ' && input[i] != '\0')
		return(-9999);
	return (i);
}

void	ft_echo(char *input)
{
	int		flag;
	int		flag_quotes;
	int		i;
	char	*echo;

	echo = "echo";
	flag_quotes = closed_quote(input, ft_strlen(input));
	i = 0;
	flag = check_forn(input, i);
	i = skip_echo(echo, input, i);
	if (i < 0)
		return ;
	i = skip_white(input, flag, i);
	while (input[i])
	{
		if (input[i] == '"' && flag_quotes)
			i++;
		else if (input[i] == '"' && !flag_quotes)
			write(1, &input[i++], 1);
		write(1, &input[i++], 1);
	}
	if (!flag)
		write(1, "\n", 1);
}
