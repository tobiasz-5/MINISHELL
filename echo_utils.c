/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:49:00 by marvin            #+#    #+#             */
/*   Updated: 2024/09/19 15:49:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

int	closed_quote(char *str, int i)
{
	int	quote;

	quote = 0;
	while (i >= 0)
	{
		if (str[i] == '"')
			quote++;
		i--;
	}
	if (quote % 2 != 0)
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
