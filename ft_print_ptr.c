/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:38:44 by jlu               #+#    #+#             */
/*   Updated: 2023/11/24 15:02:41 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long n, unsigned long base)
{
	int				count;
	char			*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (!n)
		return (count = (write (1, "0x0", 3)));
	count += write (1, "0x", 2);
	if (n < base)
		return (count += ft_print_char(symbols[n]));
	else
	{
		count += ft_print_digit(n / base, base);
		return (count + ft_print_digit(n % base, base));
	}
	return (count);
}
