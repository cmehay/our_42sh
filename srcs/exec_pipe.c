/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 20:20:23 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/24 19:08:27 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int		ms_exec_pipe_create(t_node *node)
{
	int	*pfd;
	int	ret;

	pfd = malloc(2 * sizeof(int));
	if (!pfd)
		return (-1);
	ret = pipe(pfd);
	if (ret < 0)
		free(pfd);
	else
		node->data = pfd;
	return (ret);
}

int		ms_exec_pipe(t_context *context, t_node *node)
{
	int	*pfd;
	int	ret;

	ret = ms_exec_pipe_create(node);
	if (ret >= 0)
	{
		ms_exec_tree(context, node->left);
		ret = ms_exec_tree(context, node->right);
	}
	pfd = node->data;
	close(pfd[PIPE_READ]);
	close(pfd[PIPE_WRITE]);
	return (ret);
}
