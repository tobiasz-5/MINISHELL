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

static int is_white(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static void append_char(char *cpy, int *j, char c)
{
    cpy[*j] = c;
    (*j)++;
}

int skip_white(char c, int *in_word, char *cpy, int *j)
{
    if (is_white(c))
    {
        if (*in_word)
        {
            append_char(cpy, j, ' ');
            *in_word = 0;
        }
        return (1);
    }
    return (0);
}

void ft_echo(char *input)
{
	int flag;
	int flag_quotes;
	int i;
	char *echo = "echo ";

	flag_quotes = closed_quote(input, ft_strlen(echo));
	i = 0;
	flag = check_forn(input, i);
	while (input[i] == echo[i])
		i++;
	if (flag)
		i+=3;
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
