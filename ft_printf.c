/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:20:34 by jlu               #+#    #+#             */
/*   Updated: 2023/11/20 17:13:37 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write (1, &c, 1));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_print_str(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0)
		write (1, &*str, len);
	return (len);
}

// //int	ft_print_digit(long n, int base)
// //{
// //	int count;

// //	if (n < 0)
// //	{
// //		ft_print_char("-");
// //		n *= -1;
// //	}
// //}

int	ft_print_ptr(unsigned long ptr)
{
	int		ptr_loc;
	char	*symbols;

	symbols = "0123456789abcdef";
	ptr_loc = 0;
	ptr_loc += write (1, "0x", 2);
	if (ptr == 0)
		ptr_loc += write (1, "0", 1);
	else

}

int	ft_eval_format(char spec, va_list ap) //ap = argu pointer
{
	int	resu;

	resu = 0;
	if (spec == 'c')
		resu += ft_print_char(va_arg(ap, int));
	else if (spec == 's')
		resu += ft_print_str(va_arg(ap, void *));
	//else if (spec == 'p')
	//	resu +=ft_print_ptr((unsigned long int)va_arg(ap, int *));
	//else if (spec == 'd')
	//	resu += ft_print_digit((long)va_arg(ap, int), 10);
	//else if (spec == 'x' || spec == 'X')
	//	resu += ft_print_digit((long)va_arg(ap, unsigned int), 16);
	//else if (spec == 'u')
	//	resu += ;
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
			count += write (1, &format[i], 1);
		i++;
	}
	return (count);
}

#include <stdio.h>

// int	main(void)
// {
// 	//char 	a = 'a';
// 	int 	x = 43;
// 	//int		dec = 42.42;
// 	// char 	*str = "Hello World!";

// 	// ft_printf("Now can we print this: \n");
// 	   printf("Now we can print this: %d\n", *x);
	
// 	return 0;
// }
