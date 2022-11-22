/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:19 by aperin            #+#    #+#             */
/*   Updated: 2022/11/22 08:53:39 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_free(char *str1, char *str2)
{
	free(str1);
	free(str2);
	return (0);
}

int	found_nl(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*strjoin_free(char *save, char *buf, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new_save;

	new_save = malloc((len + 1) * sizeof(char));
	if (!new_save)
		return (gnl_free(save, 0));
	i = 0;
	if (save)
	{
		while (save[i])
		{
			new_save[i] = save[i];
			i++;
		}
	}
	j = 0;
	while (buf[j])
	{
		new_save[i + j] = buf[j];
		j++;
	}
	new_save[i + j] = 0;
	free(save);
	return (new_save);
}
