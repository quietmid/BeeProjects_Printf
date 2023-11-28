/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:54:25 by jlu               #+#    #+#             */
/*   Updated: 2023/11/28 15:36:27 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_digit(long long int n, int base, char *symbols)
{
	int	count;
	int	temp;

	count = 0;
	temp = 0;
	if (n < base)
	{
		if (ft_print_char(symbols[n]) == -1)
			return (-1);
		return (count += 1);
	}
	else
	{
		temp = ft_print_digit(n / base, base);
		if (temp == -1)
			return (-1);
		count += temp;
		temp = ft_print_digit(n % base, base);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}

int	ft_print_digit(long long int n, int base)
{
	int		count;
	char	*symbols;
	int		temp;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		count++;
		n *= -1;
	}
	temp = ft_get_digit(n, base, symbols);
	if (temp == -1)
		return (-1);
	return (count += temp);
}
