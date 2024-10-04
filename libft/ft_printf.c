/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:12:17 by acapobia          #+#    #+#             */
/*   Updated: 2023/11/11 20:12:17 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_per(char c, va_list args, int *i)
{
	int	len;

	len = 0;
	if (c == '%')
		len += put_char('%');
	else if (c == 'c')
		len += put_char(va_arg(args, int));
	else if (c == 's')
		len += put_str(va_arg(args, char *));
	else if (c == 'p')
		len += put_point(va_arg(args, size_t));
	else if (c == 'd' || c == 'i')
		len += put_nbr(va_arg(args, int));
	else if (c == 'u')
		len += put_uns(va_arg(args, unsigned int));
	else if (c == 'x')
		len += put_hex(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		len += put_hex(va_arg(args, unsigned int), 'X');
	else
		i--;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += check_per(format[i], args, &i);
			i++;
		}
		if (format[i] != '\0' && format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
// int main()
// {
// 	//char *s = "";
// 	//void *ptr = 0;
// 	ft_printf("%s", "ciao");
// 	//ft_printf("NULL %s NULL", s);
// 	return 0;
// }