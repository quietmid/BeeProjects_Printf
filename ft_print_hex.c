/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:31:53 by jlu               #+#    #+#             */
/*   Updated: 2023/11/28 15:10:50 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_hex(long int nbl, int base, char spec, char *symbols)
{
	int	count;
	int	temp;

	count = 0;
	temp = 0;
	if (nbl < base)
	{
		temp = ft_print_char(symbols[nbl]);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	else
	{
		temp = ft_print_hex(nbl / base, base, spec);
		if (temp == -1)
			return (-1);
		count += temp;
		temp = ft_print_hex(nbl % base, base, spec);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}

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
	temp = ft_get_hex(nbl, base, spec, symbols);
	if (temp == -1)
		return (-1);
	return (count += temp);
}
