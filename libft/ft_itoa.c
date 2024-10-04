/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:45:01 by acapobia          #+#    #+#             */
/*   Updated: 2023/10/31 14:47:05 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_string(char *s, int i)
{
	int		j;
	char	temp;

	j = 0;
	if (s[j] == '-')
		j++;
	while (j < i)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i--;
		j++;
	}
}

static int	malloc_str_from_int(long n)
{
	int		cont;

	cont = 0;
	if (n < 0)
	{
		n *= -1;
		cont++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		cont++;
		n /= 10;
	}
	return (cont);
}

char	*ft_itoa(int n)
{
	char	*digit;
	int		i;
	long	boh;

	boh = (long)n;
	i = 0;
	digit = (char *)malloc(malloc_str_from_int(boh) + 1);
	if (!digit)
		return (NULL);
	if (boh < 0)
	{
		digit[i++] = '-';
		boh *= -1;
	}
	if (boh == 0)
		digit[i++] = '0';
	while (boh != 0)
	{
		digit[i++] = (boh % 10) + 48;
		boh /= 10;
	}
	digit[i] = '\0';
	swap_string(digit, --i);
	return (digit);
}

// int main()
// {
// 	char *s = ft_itoa(-2147483648LL);
//     if (s != NULL) {
//         printf("%s", s);
//         free(s);  // Assicurati di liberare la memoria allocata dinamicamente
//     } else {
//         printf("Errore nell'allocazione di memoria.");
//     }
// 	return 0;
// }