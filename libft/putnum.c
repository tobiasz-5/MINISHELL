/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:12:02 by girindi           #+#    #+#             */
/*   Updated: 2024/10/07 15:40:54 by girindi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_point(size_t n)
{
	char	s[25];
	char	*set;
	int		i;
	int		len;

	len = 0;
	i = 0;
	set = "0123456789abcdef";
	if (n == 0)
	{
		len += put_str("(nil)");
		return (len);
	}
	write(1, &"0x", 2);
	len += 2;
	while (n != 0)
	{
		s[i++] = set[n % 16];
		n /= 16;
	}
	while (i--)
		len += put_char(s[i]);
	return (len);
}

int	put_nbr(int n)
{
	char	s[13];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (n == -2147483648)
		len += put_str("-2147483648");
	if (n == -2147483648)
		return (len);
	if (n < 0)
	{
		len += put_char('-');
		n *= -1;
	}
	if (n == 0)
		len += put_char('0');
	while (n != 0)
	{
		s[i++] = (n % 10) + 48;
		n /= 10;
	}
	while (i-- > 0)
		len += put_char(s[i]);
	return (len);
}

int	put_uns(unsigned int n)
{
	char	s[12];
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (n == 0)
		len += put_char('0');
	while (n != 0)
	{
		s[i++] = (n % 10) + 48;
		n /= 10;
	}
	while (i-- > 0)
		len += put_char(s[i]);
	return (len);
}

int	put_hex(unsigned int n, char x)
{
	char	s[25];
	char	*set;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (x == 'X')
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	if (n == 0)
	{
		len += put_char('0');
		return (len);
	}
	while (n != 0)
	{
		s[i++] = set[n % 16];
		n /= 16;
	}
	while (i--)
		len += put_char(s[i]);
	return (len);
}
