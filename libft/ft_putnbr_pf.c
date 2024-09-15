/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:57:54 by mailinci          #+#    #+#             */
/*   Updated: 2024/05/28 13:52:52 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_pf(char ch, int *c)
{
	write(1, &ch, 1);
	(*c)++;
}

void	ft_putnbr_pf(long n, int *c)
{
	if (n < 0)
	{
		n = n * -1;
		ft_putchar_pf('-', c);
	}
	if (n < 10)
		ft_putchar_pf((char)(n + 48), c);
	else
	{
		ft_putnbr_pf(n / 10, c);
		ft_putnbr_pf(n % 10, c);
	}
}
