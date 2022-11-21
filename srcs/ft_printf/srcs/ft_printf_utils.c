/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:34:18 by aperin            #+#    #+#             */
/*   Updated: 2022/10/20 18:22:23 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

static void	ft_putnbr_base_rec(long nbr, char *base, int base_len, int *ret)
{
	if (nbr >= base_len)
		ft_putnbr_base_rec(nbr / base_len, base, base_len, ret);
	write(1, &base[nbr % base_len], 1);
	(*ret)++;
}

int	ft_putnbr_base(long nbr, char *base)
{
	int	base_len;
	int	ret;

	base_len = 0;
	ret = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		ret++;
	}
	ft_putnbr_base_rec(nbr, base, base_len, &ret);
	return (ret);
}

int	ft_putptr(unsigned long ptr, int ret)
{
	if (ptr >= 16)
		ret += ft_putptr(ptr / 16, 0);
	write(1, &HEXA_LOWER[ptr % 16], 1);
	return (ret + 1);
}
