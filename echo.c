/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:11:43 by girindi           #+#    #+#             */
/*   Updated: 2024/10/10 12:21:18 by negambar         ###   ########.fr       */
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

int	skip_echo(char *echo, char *input, int i)
{
	int	j;
	int	closed;

	j = 0;
	closed = closed_quote(input, i);
	while (echo[i])
	{
		while ((input[j] == '\'' || input[j] == '"') && closed)
			j++;
		if (input[j] != echo[i])
			return (-99999);
		i++;
		j++;
	}
	while (input[j] == '\'' || input[j] == '"')
		j++;
	if (input[j] != ' ' && input[j] != '\0')
		return (-9999);
	return (j);
}

void	ft_echo(char *input)
{
	int		flag;
	int		i;

	i = skip_echo("echo", input, 0);
	flag = check_forn(input, i);
	if (i < 0)
		return ;
	i = skip_white(input, flag, i);
	while (input[i])
	{
		if (!closed_quote(input, ft_strlen(input)))
			return ;
		if ((input[i] == '"' || input[i] == '\''))
		{
			if ((input[i + 1] == '"' || input[i + 1] == '\''))
			{
				i++;
				continue ;
			}
			i = quotes_handling(input, i);
		}
		write(1, &input[i++], 1);
	}
	if (!flag)
		write(1, "\n", 1);
}
