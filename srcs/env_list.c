/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 17:19:07 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/26 23:37:21 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

t_env	*ms_env_lstadd(t_context *context, char *var)
{
	t_env	*elem;
	t_env	*current;

	if ((elem = (t_env *) cool_malloc(sizeof(t_env))) == NULL)
		return ((t_env *) ms_function_failed("cool_malloc failed", NULL));
	elem->name = ms_var_name_get(var);
	elem->value = ms_var_value_get(var);
	if (elem->name == NULL || elem->value == NULL)
		return (NULL);
	elem->prev = NULL;
	elem->next = NULL;
	if (context->env == NULL)
	{
		context->env = elem;
		return (elem);
	}
	current = context->env;
	while (current->next)
		current = current->next;
	elem->prev = current;
	current->next = elem;
	return (context->env);
}

void	ms_env_lstdelone(t_env **current)
{
	t_env	*next;
	t_env	*prev;

	if (*current)
	{
		next = (*current)->next;
		prev = (*current)->prev;
		if ((*current)->prev)
			(*current)->prev->next = next;
		if ((*current)->next)
			(*current)->next->prev = prev;
		cool_free((*current)->name);
		cool_free((*current)->value);
		cool_free(*current);
		*current = next;
	}
}

void	ms_env_lstdel(t_context *context)
{
	t_env	*current;
	t_env	*next;

	current = context->env;
	while (current)
	{
		next = current->next;
		cool_free(current->name);
		cool_free(current->value);
		cool_free(current);
		current = next;
	}
	current = NULL;
}

t_env	*ms_env_get(t_context *context)
{
	int		i;

	i = 0;
	while (context->environ[i])
	{
		context->env = ms_env_lstadd(context, context->environ[i]);
		if (context->env == NULL)
			return (NULL);
		i++;
	}
	return (context->env);
}
