/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:05:16 by negambar          #+#    #+#             */
/*   Updated: 2024/10/05 13:05:16 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void	ft_pwd(void)
{
	char	*pwd;
	printf("pwd\n");

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		printf("Error pwd malloc");
		return ;
	}
	printf("%s\n", pwd);
	free (pwd);
	return ;
}
