/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:39:42 by acapobia          #+#    #+#             */
/*   Updated: 2023/12/05 19:58:43 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*next;

	ptr = *lst;
	while (ptr != NULL)
	{
		next = ptr -> next;
		del(ptr -> content);
		free(ptr);
		ptr = next;
	}
	*lst = NULL;
}
