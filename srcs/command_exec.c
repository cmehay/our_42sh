/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 20:20:23 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/25 22:25:04 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

static char	*ms_var_join(char const *s1, char const *s2)
{
	size_t	len;
	size_t	len1;
	char	*var;

	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2) + 1;
	var = (char*)cool_malloc(sizeof(char) * (len + 2));
	if (var == NULL)
		return (NULL);
	ft_strcpy(var, s1);
	var[len1] = '=';
	ft_strcpy(&var[len1 + 1], s2);
	return (var);
}

char		**ms_env_clone(t_env *env)
{
	char	**environ;
	size_t	i;
	t_env	*current;

	i = 0;
	current = env;
	while (current)
	{
		current = current->next;
		i++;
	}
	if ((environ = (char**)cool_malloc(sizeof(char*) * (i + 1))) == NULL)
		return ((char**)ms_function_failed("cool_malloc failed", NULL));
	i = 0;
	current = env;
	while (current)
	{
		environ[i] = ms_var_join(current->name, current->value);
		if (environ[i] == NULL)
			return ((char**)ms_function_failed("cool_malloc failed", NULL));
		i++;
		current = current->next;
	}
	environ[i] = NULL;
	return (environ);
}
