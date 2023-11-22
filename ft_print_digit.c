/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:54:25 by jlu               #+#    #+#             */
/*   Updated: 2023/11/22 17:54:45 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(int n, int base)
{
	long	nbl;
	int 	count;
	char	*symbols;

	nbl = n;
	count = 0;
	symbols = "0123456789";
	if (nbl < 0)
	{	
		if (ft_print_char('-') == -1)
			return (-1);
		count++;
		nbl *= -1;
	}
	if (nbl < base)
		return ft_print_char(symbols[nbl]);
	else
	{
		count += ft_print_digit(nbl / base, base);
		return count + ft_print_digit(nbl % base, base);
	}
	return (count);
}
