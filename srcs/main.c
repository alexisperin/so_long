/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:08:54 by aperin            #+#    #+#             */
/*   Updated: 2022/11/21 18:10:41 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	(void) av;
	if (ac < 2)
		return (print_error("Not enough input argument"));
	if (ac > 2)
		return (print_error("Too many input arguments"));
}
