/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:21 by aperin            #+#    #+#             */
/*   Updated: 2022/11/22 08:54:17 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*after_nl(char *save, size_t nl_index)
{
	size_t	i;
	char	*res;

	i = 0;
	while (save[nl_index + i])
		i++;
	if (!i)
		return (gnl_free(save, 0));
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (gnl_free(save, 0));
	i = 0;
	while (save[nl_index + i])
	{
		res[i] = save[nl_index + i];
		i++;
	}
	res[i] = 0;
	free(save);
	return (res);
}

static char	*until_nl(char *save, size_t *nl_index)
{
	size_t	i;
	char	*res;

	if (save[0] == 0)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	*nl_index = i;
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < *nl_index)
	{
		res[i] = save[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

static char	*read_line(int fd, char *save)
{
	char	*buf;
	int		ret;
	size_t	save_len;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (gnl_free(save, 0));
	buf[0] = 0;
	ret = 1;
	save_len = ft_strlen(save);
	while (ret && !found_nl(buf))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (gnl_free(save, buf));
		buf[ret] = 0;
		save_len += ret;
		save = strjoin_free(save, buf, save_len);
		if (!save)
			return (gnl_free(buf, 0));
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*res;
	size_t		nl_index;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!found_nl(save))
	{
		save = read_line(fd, save);
		if (!save)
			return (0);
	}
	res = until_nl(save, &nl_index);
	if (!res)
	{
		free(save);
		save = 0;
		return (0);
	}
	save = after_nl(save, nl_index);
	return (res);
}
