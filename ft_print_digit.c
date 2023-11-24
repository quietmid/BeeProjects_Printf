/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:54:25 by jlu               #+#    #+#             */
/*   Updated: 2023/11/24 14:26:02 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(long long int n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		count++;
		n *= -1;
	}
	if (n < base)
	{
		if (ft_print_char(symbols[n]) == -1)
			return (-1);
		return (count += 1);
	}
	else
	{
		count += ft_print_digit(n / base, base);
		return (count += ft_print_digit(n % base, base));
	}
}
