/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:43:56 by misikogl          #+#    #+#             */
/*   Updated: 2022/05/30 20:25:43 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_check(char c, va_list safe);
int	ft_put_str(char *str);
int	ft_put_char(char c);
int	ft_put_ptr( unsigned long int ptr);
int	ft_put_hex(unsigned int nb, int s);
int	ft_put_unsigned_int(unsigned int nb);
int	ft_put_nbr(int nb);

#endif
