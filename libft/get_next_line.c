/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:35:43 by acapobia          #+#    #+#             */
/*   Updated: 2023/11/27 18:35:43 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

#include "libft.h"
//#include <stdio.h>

char	*ft_salva_spazio(char *s, char *buf, int n)
{
	char	*temp;

	temp = s;
	s = ft_strjoin_plus(temp, buf, (size_t)n);
	free(temp);
	if (!s)
	{
		s = NULL;
		return (s);
	}
	return (s);
}

char	*new_call(int fd, char *buf, char *s)
{
	int		byte_read;

	byte_read = 1;
	while (byte_read > 0)
	{
		if (!s)
			s = ft_calloc(1, sizeof (char *));
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read <= 0)
		{
			if (ft_strlen(s) == 0)
			{
				free(s);
				s = NULL;
			}
			break ;
		}
		s = ft_salva_spazio(s, buf, byte_read);
		if (ft_strchr(s, '\n') || byte_read <= 0)
			break ;
	}
	return (s);
}

char	*check_call(char **line, char *s)
{
	char	*temp;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++ ;
	*line = ft_substr(s, 0, ++i);
	temp = ft_substr(s, 0, ft_strlen(s));
	free(s);
	if (temp)
		s = ft_substr(temp, i, ft_strlen(temp) - i);
	else
		s = NULL;
	if (!s)
	{
		free(s);
	}
	free(temp);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s = NULL;
	char		*buf;

	if (fd < 0)
		return (NULL);
	line = NULL;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	if (!buf)
		return (NULL);
	s = new_call(fd, buf, s);
	free(buf);
	s = check_call(&line, s);
	if (!line || !(*line))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
// int main()
// {
//     char *s;
//     int fd = open("test.txt", O_RDONLY);
// 	for(int i = 1; i <= 2 ; i++)
// 	{
// 		s = get_next_line(fd);
// 		printf("riga %i :%s\n",i ,s);
// 		free(s);
// 	}
// 	while (s != NULL)
// 	{
// 		s = get_next_line(fd);
// 	}
// 	s = get_next_line(fd);
// 	printf("riga %i :%s\n",5 ,s);
// 	close(fd);
// 	fd = open("test.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("riga %i :%s\n",5 ,s);
// 	close(fd);
// 	return 0;
// }