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

int first_double(char *input)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"')
			return (1);
		else if (input[i] == '\'')
			return (0);
		i++;
	}
	return (0);
}

int first_single(char *input)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			return (1);
		else if (input[i] == '"')
			return (0);
		i++;
	}
	return(0);
}

void	ft_echo(char *input)
{
	int		flag;
	int		flag_quotes;
	int		i;
	char	*echo;
	int		double_quotes;
	int		single_quotes;

	echo = "echo";
	flag_quotes = closed_quote(input, ft_strlen(input));
	double_quotes = first_double(input);
	single_quotes = first_single(input);
	i = 0;
	flag = check_forn(input, i);
	i = skip_echo(echo, input, i);
	if (i < 0)
		return ;
	i = skip_white(input, flag, i);
	while (input[i])
	{
		
		if ((input[i] == '"' || input[i] == '\'') && flag_quotes)
		{
			if (input[i+1] == '"' || input[i+1] == '\'')
			{
				i++;
				flag_quotes--;
				continue ;
			}
			if (input[i] == '"' && double_quotes)
			{
				i++;
				continue ;
			}
			else if (input[i] == '\'' && single_quotes)
			{
				i++;
				continue;
			}
		}
		else if ((input[i] == '"' || input[i] == '\'') && !flag_quotes)
			write(1, &input[i++], 1);
		write(1, &input[i++], 1);
	}
	if (!flag)
		write(1, "\n", 1);
}
