/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:31:53 by jlu               #+#    #+#             */
/*   Updated: 2023/11/24 15:12:23 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int base, char spec)
{
	long	nbl;
	int		count;
	char	*symbols;
	int		temp;

	temp = 0;
	nbl = n;
	count = 0;
	if (spec == 'x')
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (nbl < base)
		temp = ft_print_char(symbols[nbl]);
	else
	{
		count += ft_print_hex(nbl / base, base, spec);
		return (count + ft_print_hex(nbl % base, base, spec));
	}
	if (temp == -1)
		return (-1);
	return (count + temp);
}
