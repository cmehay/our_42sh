/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 19:01:36 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/22 20:45:14 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

t_node	*ms_ast_node_alloc(t_node *parent, t_direction dir, t_nodetype type)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (node)
	{
		node->type = type;
		node->data = NULL;
		node->cleanup = NULL;
		node->right = NULL;
		node->left = NULL;
		node->parent = parent;
		if (dir == DIR_LEFT)
			parent->left = node;
		if (dir == DIR_RIGHT)
			parent->right = node;
	}
	return (node);
}

void	ms_ast_node_clean(t_node **node)
{
	if ((*node)->data)
	{
		if (!(*node)->cleanup)
			(*node)->cleanup = free;
		(*node)->cleanup((*node)->data);
	}
	free(*node);
	*node = NULL;
}
