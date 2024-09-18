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

static int skip_white(char c, int *in_word, char *cpy, int *j)
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

static char *ft_strcpy_no_space(char *s)
{
    char *cpy;
    int i;
    int j;
    int in_word;

    cpy = (char *)malloc(strlen(s) + 1);
    if (!cpy)
        return (NULL);
    i = 0;
    j = 0;
    in_word = 0;
    while (s[i])
    {
        if (!skip_white(s[i], &in_word, cpy, &j))
            append_char(cpy, &j, s[i]);
        if (!skip_white(s[i], &in_word, cpy, &j))
            in_word = 1;
        i++;
    }
    if (j > 0 && cpy[j - 1] == ' ')
        j--;
    cpy[j] = '\0';
    return (cpy);
}

void ft_echo(char *input)
{
	char *cpy;
	int n_flag = 0;
	int start = 5;

	cpy = ft_strcpy_no_space(input);
	if (!cpy)
		return;
	if (strncmp(cpy, "echo -n", 7) == 0 && (is_white(cpy[7]) || cpy[7] == '\0'))
	{
		n_flag = 1;
		start = 8;
	}
	while (cpy[start] && is_white(cpy[start]))
		start++;
	write(1, &cpy[start], strlen(&cpy[start]));
	if (!n_flag)
		write(1, "\n", 1);
	free(cpy);
}
