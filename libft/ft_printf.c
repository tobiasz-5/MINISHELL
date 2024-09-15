/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:38:30 by mailinci          #+#    #+#             */
/*   Updated: 2024/05/28 13:48:23 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *str, ...);
void	ft_puthexmempf(void *str, int *c);
void	ft_putstrpf(char *str, int *c);
void	ft_vcheck(const char v, va_list ptr, int *c);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		c;

	i = 0;
	c = 0;
	va_start(ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_vcheck(str[i + 1], ptr, &c);
			i++;
		}
		else
			ft_putchar_pf(str[i], &c);
		i++;
	}
	va_end(ptr);
	return (c);
}

void	ft_vcheck(const char v, va_list ptr, int *c)
{
	if (v == 'c')
		ft_putchar_pf((char)(va_arg(ptr, int)), c);
	if (v == 's')
		ft_putstrpf((va_arg(ptr, char *)), c);
	if (v == 'd' || v == 'i')
		ft_putnbr_pf(va_arg(ptr, int), c);
	if (v == 'u')
		ft_putnbr_pf((unsigned int)va_arg(ptr, int), c);
	if (v == 'x')
		ft_puthexnbr_pf((unsigned int)va_arg(ptr, int), "0123456789abcdef", c);
	if (v == 'X')
		ft_puthexnbr_pf((unsigned int)va_arg(ptr, int), "0123456789ABCDEF", c);
	if (v == 'p')
		ft_puthexmempf(va_arg(ptr, void *), c);
	if (v == '%')
		ft_putchar_pf('%', c);
}

void	ft_puthexmempf(void *str, int *c)
{
	unsigned long	mem;

	if (str == NULL)
	{
		write(1, "(nil)", 5);
		*c = *c + 5;
	}
	else
	{
		mem = (unsigned long)str;
		ft_putstrpf("0x", c);
		ft_puthexnbr_pf(mem, "0123456789abcdef", c);
	}
}

void	ft_putstrpf(char *str, int *c)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*c = *c + 6;
	}
	else
	{
		while (str[i] != '\0')
		{
			ft_putchar_pf(str[i], c);
			i++;
		}
	}
}
