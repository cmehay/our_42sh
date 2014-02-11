/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 17:49:08 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/03 13:22:44 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFF_SIZE 42

char	*ft_strextend(char *s1, const char *s2)
{
	char	*str_new;

	if (s1 == NULL)
		return (ft_strdup(s2));
	str_new = ft_strjoin(s1, s2);
	free(s1);
	return (str_new);
}

int		g_n_l_from_stash(char *tmp, char **line, char **stash)
{
	*tmp = '\0';
	*line = *stash;
	*stash = NULL;
	if (tmp[1] != '\0')
	{
		*stash = ft_strdup(&tmp[1]);
		if (*stash == NULL)
		{
			free(*line);
			return (-1);
		}
	}
	return (1);
}

int		g_n_l_from_buf(char *buf, char *tmp, char **line, char **stash)
{
	*tmp = '\0';
	*line = ft_strextend(*stash, buf);
	*stash = NULL;
	if (*line == NULL)
		return (-1);
	if (tmp[1] != '\0')
	{
		*stash = ft_strdup(&tmp[1]);
		if (*stash == NULL)
		{
			free(*line);
			return (-1);
		}
	}
	return (1);
}

int		get_last_line(char **line, char **stash)
{
	if (*stash == NULL)
		return (0);
	*line = *stash;
	*stash = NULL;
	return (1);
}

int		ft_gnl(int const fd, char **line)
{
	static char	*stash = NULL;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		ret;

	if ((stash != NULL) && (tmp = ft_strchr(stash, '\n')))
		return (g_n_l_from_stash(tmp, line, &stash));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
		{
			free(stash);
			stash = NULL;
			return (-1);
		}
		buf[ret] = '\0';
		if ((tmp = ft_strchr(buf, '\n')))
			return (g_n_l_from_buf(buf, tmp, line, &stash));
		stash = ft_strextend(stash, buf);
		if (stash == NULL)
			return (-1);
	}
	if (ret == 0)
		return (get_last_line(line, &stash));
	return (-1);
}
