/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:17:51 by girindi           #+#    #+#             */
/*   Updated: 2024/10/08 18:22:05 by girindi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

static int	first_double(char *input)
{
	int	i;

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

static int	first_single(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			return (1);
		else if (input[i] == '"')
			return (0);
		i++;
	}
	return (0);
}

int	closed_quote(char *str, int i)
{
	int	quote;
	int	quote2;

	quote = 0;
	quote2 = 0;
	while (i >= 0)
	{
		if (str[i] == '"')
			quote++;
		else if (str[i] == '\'')
			quote2++;
		i--;
	}
	if (quote % 2 != 0 || quote2 % 2 != 0)
		return (0);
	return (1);
}

int	check_forn(char *input, int i)
{
	int	flag;

	flag = 0;
	while (input[i])
	{
		if (input[i] == '-' && input[i + 1] == 'n')
			flag = 1;
		if (input[i] != 'e' && input[i] != 'c' && input[i] != 'h'
			&& input[i] != 'o' && input[i] != ' ')
			break ;
		i++;
	}
	return (flag);
}

int	quotes_handling(char *input, int i)
{
	int	double_quotes;
	int	single_quotes;

	double_quotes = first_double(input);
	single_quotes = first_single(input);
	if (input[i] == '"' && double_quotes)
		i++;
	else if (input[i] == '\'' && single_quotes)
		i++;
	return (i);
}
