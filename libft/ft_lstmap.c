/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:56:35 by girindi           #+#    #+#             */
/*   Updated: 2024/10/07 15:40:54 by girindi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;
	void	*sos;

	sos = NULL;
	if (!f || !del)
		return (NULL);
	ptr = NULL;
	while (lst)
	{
		sos = f(lst -> content);
		new = ft_lstnew(sos);
		if (!new)
		{
			del(sos);
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		lst = lst -> next;
		ft_lstadd_back(&ptr, new);
	}
	return (ptr);
}
