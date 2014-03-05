/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 17:56:05 by dcouly            #+#    #+#             */
/*   Updated: 2014/02/18 23:02:27 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

t_str	*ms_str_lstadd(char *var, t_str **l_str)
{
	t_str	*elem;
	t_str	*current;

	if ((elem = (t_str *) cool_malloc(sizeof(t_str))) == NULL)
		return ((t_str *) ms_function_failed("cool_malloc failed", NULL));
	elem->str = cool_strdup(var);
	if (elem->str == NULL)
		return (NULL);
	elem->next = NULL;
	if (*l_str == NULL)
	{
		*l_str = elem;
		return (elem);
	}
	current = *l_str;
	while (current->next)
		current = current->next;
	current->next = elem;
	return (*l_str);
}

void	ms_str_lstdel(t_str **l_str, int fd)
{
	t_str	*current;
	t_str	*next;

	current = *l_str;
	while (current)
	{
		ft_putendl_fd(current->str, fd);
		next = current->next;
		cool_free(current->str);
		cool_free(current);
		if (next == NULL)
			break ;
		current = next;
	}
	current = NULL;
}
