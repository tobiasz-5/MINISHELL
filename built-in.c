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

static char *ft_strcpy(char *s)
{
	char *cpy;
	int i;

	i = 0;
	while (s[i])
		i++;
	cpy = (char *)malloc(sizeof(char) *(i+1));
	if (!cpy)
		return (NULL);
	i = 0;
	while(s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return(cpy);
}

int handle_builtins(char *input, char *cmd)
{
	if (ft_strcmp(input, cmd) == 0)
	{
		printf("Farewell my friend\n");
		return (1);
	}
	return (0);
}

void ft_echo(char *input, int n)
{
	char *cpy;
	cpy = ft_strcpy(input);
	if (!cpy)
		return ;
	if (ft_strncmp(cpy, "echo -n", 6) == 0)
		n = 8;
	else
		n = 5;
	while(cpy[n])
	{
		write(1, &cpy[n], 1);
		n++;
	}
	if (ft_strncmp(input, "echo -n", 6) != 0)
		write(1, "\n", 1);
	free(cpy);
}