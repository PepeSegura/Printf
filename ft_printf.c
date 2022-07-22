/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 01:16:38 by psegura-          #+#    #+#             */
/*   Updated: 2022/07/22 10:57:41 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, char format)
{
	int	dest;

	dest = 0;
	if (format == '%')
		dest += ft_putchar('%');
	else if (format == 'c')
		dest += ft_putchar(va_arg(args, int));
	else if (format == 's')
		dest += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		dest += ft_pointer(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		dest += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		dest += ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (format == 'x')
		dest += ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (format == 'X')
		dest += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else
		dest += ft_putstr(va_arg(args, char *));
	return (dest);
}

int	ft_printf(char const *string, ...)
{
	va_list	args;
	int		d_type;
	int		i;

	d_type = 0;
	i = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			d_type = d_type + ft_format(args, string[i + 1]);
			i++;
		}
		else
			d_type = d_type + write(1, &string[i], 1);
		i++;
	}
	return (d_type);
}
/*
int	main(void)
{
	char	*str;
	char	c;
	int		nbr;

	str = "HOLA";
	c = 'b';	
	nbr = 1234567890;
	ft_printf(" -> Size %d", ft_printf("%s", str));
	ft_putchar('\n');
	ft_printf(" -> Size %d", ft_printf("%c", c));
	ft_putchar('\n');
	ft_printf(" -> Size %d", ft_printf("%d", nbr));
	ft_putchar('\n');
	ft_printf(" -> Size %d", ft_printf("%i", nbr));
	ft_putchar('\n');
	ft_printf(" -> Size %d", ft_printf("%x", nbr));
	ft_putchar('\n');
	ft_printf(" -> Size %d", ft_printf("%X", nbr));
	ft_putchar('\n');
	return (0);
}
*/
