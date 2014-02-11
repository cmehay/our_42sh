/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:52:02 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/24 18:42:53 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

t_context	*ms_context_get(void)
{
	static t_context	*context = NULL;

	if (context == NULL)
	{
		if ((context = (t_context *) malloc(sizeof(t_context))) == NULL)
			return ((t_context *) ms_function_failed("malloc failed", NULL));
		return (context);
	}
	else
		return (context);
}

void		ms_context_init(t_context *context)
{
	context->environ = NULL;
	context->env = NULL;
	context->processes = NULL;
	context->term = NULL;
	context->history = NULL;
}

t_context	*ms_context_fill(t_context *context, char **environ)
{
	context->environ = environ;
	context->env = ms_env_get(context);
	if (context->env == NULL)
		return (NULL);
	if ((context->term = (t_term *) malloc(sizeof(t_term))) == NULL)
		return (NULL);
	return (context);
}

void		ms_context_clean(t_context *context)
{
	t_env	*current;

	current = context->env;
	while (current)
		ms_env_lstdelone(&current);
	free(context->term);
	ms_history_lstdel(context->history);
	free(context);
}
