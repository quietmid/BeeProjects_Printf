/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:20:34 by jlu               #+#    #+#             */
/*   Updated: 2023/11/24 15:38:52 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_format(char spec, va_list ap)
{
	int	resu;
	int	temp;

	temp = 0;
	resu = 0;
	if (spec == 'c')
		temp = (ft_print_char(va_arg(ap, int)));
	else if (spec == 's')
		resu += ft_print_str(va_arg(ap, char *));
	else if (spec == 'p')
		resu += ft_print_ptr(va_arg(ap, unsigned long), 16);
	else if (spec == 'd' || spec == 'i')
		resu += ft_print_digit(va_arg(ap, int), 10);
	else if (spec == 'u')
		resu += ft_print_digit((unsigned)va_arg(ap, int), 10);
	else if (spec == 'x' || spec == 'X' || spec == 'p')
		resu += ft_print_hex(va_arg(ap, unsigned long), 16, spec);
	else if (spec == '%')
		temp = (ft_print_char('%'));
	else
		temp = write (1, &spec, 1);
	if (temp == -1)
		return (-1);
	return (resu + temp);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		temp;

	if (!format || *format == '\0')
		return (0);
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		temp = 0;
		if (format[i] == '%')
			temp = ft_eval_format(format[++i], ap);
		else
			temp = write (1, &format[i], 1);
		i++;
		if (temp == -1)
			return (-1);
		count += temp;
	}
	va_end(ap);
	return (count);
}

//#include <stdio.h>

//int	main(void)
//{
//	//char 	a = 'a';
//	int		ret;
//	//int 	x = -2147483648;
//	//int		dec = 42.42;
//	//char 	*str = "Hello World!";
	
//	ret = ft_printf("%%c\n");
//	ft_printf("%i\n", ret);
//	ret = printf("%%c\n");
//	printf("%i\n", ret);
	
//	return 0;
//}