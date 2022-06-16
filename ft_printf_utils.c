/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:43:56 by misikogl          #+#    #+#             */
/*   Updated: 2022/05/30 20:25:09 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(int nb)
{
	int		len;
	long	n;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += ft_put_char('-');
		n = -n;
	}
	if (n >= 10)
	{
		len += ft_put_nbr(n / 10);
		len += ft_put_nbr(n % 10);
	}
	if (n < 10)
	{
		len += ft_put_char(n + 48);
	}
	return (len);
}

int	ft_put_unsigned_int(unsigned int nb)
{	
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_put_unsigned_int(nb / 10);
		len += ft_put_unsigned_int(nb % 10);
	}
	if (nb < 10)
		len += ft_put_char(nb + 48);
	return (len);
}

int	ft_put_hex(unsigned int nb, int s)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_put_hex(nb / 16, s);
		len += ft_put_hex(nb % 16, s);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += ft_put_char(nb + 48);
		else
		{
			if (s == 1)
				len += ft_put_char((nb + 87));
			else
				len += ft_put_char((nb + 55));
		}
	}
	return (len);
}

int	ft_put_ptr( unsigned long int ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
	{
		len += ft_put_ptr(ptr / 16);
		len += ft_put_ptr(ptr % 16);
	}
	if (ptr < 16)
	{
		if (ptr < 10)
			len += ft_put_char(ptr + 48);
		else
			len += ft_put_char(ptr + 87);
	}
	return (len);
}
