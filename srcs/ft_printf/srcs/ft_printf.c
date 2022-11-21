/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:48:30 by aperin            #+#    #+#             */
/*   Updated: 2022/10/21 10:47:54 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(va_list ap, char c, int *len)
{
	if (c == 'c')
		*len += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		*len += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		*len += 2;
		*len += ft_putptr(va_arg(ap, unsigned long), 0);
	}
	else if (c == 'd' || c == 'i')
		*len += ft_putnbr_base(va_arg(ap, int), DECIMAL);
	else if (c == 'u')
		*len += ft_putnbr_base(va_arg(ap, unsigned), DECIMAL);
	else if (c == 'x')
		*len += ft_putnbr_base(va_arg(ap, unsigned), HEXA_LOWER);
	else if (c == 'X')
		*len += ft_putnbr_base(va_arg(ap, unsigned), HEXA_UPPER);
	else if (c == '%')
		*len += ft_putchar('%');
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			len;
	va_list		ap;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			write(1, &str[i], 1);
			len++;
			i++;
		}
		if (str[i] == '%')
		{
			if (!print_format(ap, str[i + 1], &len))
				break ;
			i += 2;
		}
	}
	va_end(ap);
	return (len);
}
