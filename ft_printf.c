/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:20:34 by jlu               #+#    #+#             */
/*   Updated: 2023/11/22 18:26:25 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_format(char spec, va_list ap)
{
	int	resu;

	resu = 0;
	if (spec == 'c')
		resu += ft_print_char(va_arg(ap, int));
	else if (spec == 's')
		resu += ft_print_str(va_arg(ap, char *));
	//else if (spec == 'p')
	//	resu +=ft_print_ptr();
	else if (spec == 'd' || spec == 'i')
		resu += ft_print_digit(va_arg(ap, int), 10);
	else if (spec == 'u')
		resu += ft_print_digit((unsigned)va_arg(ap, int), 10);
	else if (spec == 'x' || spec == 'X')
		resu += ft_print_digit(va_arg(ap, unsigned int), 16);
	else if (spec == '%')
		resu += ft_print_char('%');
	else
		resu += write (1, &spec, 1);
	return (resu);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	
	if (!format || *format == '\0')
		return (0);
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count += ft_eval_format(format[++i], ap);
		else
		{
			//count += ft_print_char(format[i]);
			if (write (1, &format[i], 1) == -1)
				return (-1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	char 	a = 'a';
	int		ret;
	int 	x = -2147483648;
	//int		dec = 42.42;
	//char 	*str = "Hello World!";
	
	ret = ft_printf("Now can we print this: %d %c\n", x, a);
	ft_printf("%i\n", ret);
	ret = printf("Now we can print this: %d %c\n", x, a);
	printf("%i\n", ret);
	
	return 0;
}