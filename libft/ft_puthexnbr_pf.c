/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:57:49 by mailinci          #+#    #+#             */
/*   Updated: 2024/05/28 13:53:13 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexnbr_pf(unsigned long n, char *tab, int *c)
{
	if ((n / 16) != 0)
		ft_puthexnbr_pf((n / 16), tab, c);
	ft_putchar_pf(tab[n % 16], c);
}
