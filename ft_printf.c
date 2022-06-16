/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:46:08 by misikogl          #+#    #+#             */
/*   Updated: 2022/05/30 21:02:50 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_put_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

int	ft_check(char c, va_list safe)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_put_char(va_arg(safe, int));
	if (c == 's')
		len += ft_put_str(va_arg(safe, char *));
	if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_put_ptr(va_arg(safe, unsigned long int));
	}
	if (c == 'd' || c == 'i')
		len += ft_put_nbr(va_arg(safe, int));
	if (c == 'u')
		len += ft_put_unsigned_int(va_arg(safe, unsigned int));
	if (c == 'x')
		len += ft_put_hex(va_arg(safe, unsigned int), 1);
	if (c == 'X')
		len += ft_put_hex(va_arg(safe, unsigned int), 2);
	if (c == '%')
		len += ft_put_char('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int			len;
	int			i;
	va_list		safe;

	len = 0;
	i = 0;
	va_start(safe, s);
	while (s[i])
	{
		if (s[i] != '%')
			len += write(1, &s[i], 1);
		if (s[i] == '%')
		{
			len += ft_check(s[i + 1], safe);
			i++;
		}
		i++;
	}
	va_end(safe);
	return (len);
}
