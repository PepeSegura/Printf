/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:23:34 by psegura-          #+#    #+#             */
/*   Updated: 2022/07/22 10:42:52 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, char *b)
{
	long int	number;
	static int	i;

	number = (unsigned int)nbr;
	i = 0;
	if (number >= ft_strlen(b))
	{
		ft_putnbr_base(number / ft_strlen(b), b);
		number = number % ft_strlen(b);
	}
	i++;
	ft_putchar(b[number]);
	return (i);
}

int	ft_put_ex(size_t nbr)
{
	char		*base;
	static int	i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_put_ex(nbr / 16);
		nbr = nbr % 16;
	}
	i++;
	ft_putchar(base[nbr]);
	return (i);
}

int	ft_putnbr(int nbr)
{
	long int	number;
	static int	i;

	number = (long long)nbr;
	i = 0;
	if (number < 0)
	{
		write(1, "-", 1);
		number = number * -1;
	}
	if (number > 9)
	{
		ft_putnbr(number / 10);
		number = number % 10;
	}
	i++;
	ft_putchar(number + '0');
	if (nbr < 0)
		i++;
	return (i);
}

int	ft_pointer(void *p)
{
	size_t	num;
	int		len;

	len = 0;
	num = (size_t)p;
	len = write(1, "0x", 2);
	len += ft_put_ex(num);
	return (len);
}
