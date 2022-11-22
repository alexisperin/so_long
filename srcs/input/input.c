/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:02:51 by aperin            #+#    #+#             */
/*   Updated: 2022/11/22 09:12:46 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	check_input(int ac, char **av)
{
	int		len;
	char	*str;

	if (ac < 2)
		return (print_error("Not enough input argument"));
	if (ac > 2)
		return (print_error("Too many input arguments"));
	str = av[1];
	len = ft_strlen(str);
	if (len < 5 || str[len - 4] != '.' || str[len - 3] != 'b'
		|| str[len - 2] != 'e' || str[len - 1] != 'r')
		return (print_error("Invalid file extension"));
	return (1);
}
