/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_name_value_get.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 18:34:42 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/05 02:32:53 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

char	*ms_var_name_get(char *var)
{
	char	*name;
	int		i;

	i = 0;
	while (var[i] != '=' && var[i] != '\0')
		i++;
	if (var[i] == '\0')
		return (NULL);
	name = cool_strsub(var, 0, i);
	if (i == 0)
		name = cool_strsub(var, 0, 1);
	if (name == NULL)
		return ((char *) ms_function_failed("cool_malloc failed", NULL));
	return (name);
}

char	*ms_var_value_get(char *var)
{
	char	*value;
	int		i;

	i = 0;
	while (var[i] != '=' && var[i] != '\0')
		i++;
	if (var[i] == '\0')
		return (NULL);
	i++;
	value = cool_strsub(var, i, ft_strlen(var) - i);
	if (value == NULL)
		return ((char *) ms_function_failed("cool_malloc failed", NULL));
	return (value);
}

t_env	*ms_var_ptr_get(t_context *context, char *name)
{
	t_env	*current;

	current = context->env;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_env	*ms_env_get_content(t_env *env, char *name)
{
	t_env	*current;

	current = env;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
