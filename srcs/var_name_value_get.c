/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_name_value_get.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 18:34:42 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/22 17:05:07 by sbethoua         ###   ########.fr       */
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
	name = ft_strsub(var, 0, i);
	if (i == 0)
		name = ft_strsub(var, 0, 1);
	if (name == NULL)
		return ((char *) ms_function_failed("malloc failed", NULL));
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
	value = ft_strsub(var, i, ft_strlen(var) - i);
	if (value == NULL)
		return ((char *) ms_function_failed("malloc failed", NULL));
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
