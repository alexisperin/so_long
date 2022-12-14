/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:44:35 by aperin            #+#    #+#             */
/*   Updated: 2022/11/22 11:58:17 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	print_error(char *str, int call_perror)
{
	ft_putstr_fd("Error\n", 2);
	if (call_perror)
		perror(0);
	else
		ft_putstr_fd(str, 2);
	return (0);
}
