/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:49:55 by acapobia          #+#    #+#             */
/*   Updated: 2023/12/03 20:59:14 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c +32;
	return (c);
}
/*
int main()
{
	char c = 'a';
	char res = ft_tolower(c);
	write(1, &res, 1);
	return 0;
}*/
