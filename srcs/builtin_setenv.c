/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/01/20 18:06:04 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/29 19:21:56 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

static int	ms_setenv_exec_env(t_context *context, char **argv, int outfd)
{
	if (argv[1] == NULL)
	{
		ms_builtin_env(context, argv, outfd);
		return (1);
	}
	return (0);
}

static void	ms_setenv_exists(t_env **var, char *value, char **name)
{
	free((*var)->value);
	(*var)->value = value;
	free(*name);
}

int			ms_builtin_setenv(t_context *context, char **argv,
		int __UNUSED__ outfd)
{
	char	*name;
	char	*value;
	t_env	*var;
	int		i;

	if (ms_setenv_exec_env(context, argv, outfd) == 1)
		return (1);
	i = 1;
	while (argv[i])
	{
		name = ms_var_name_get(argv[i]);
		value = ms_var_value_get(argv[i]);
		if (name == '\0' || ft_strcmp(name, "=") == 0 || value == '\0')
			return (ms_err_ret("Usage: setenv <name>=<value> ...", 1));
		if ((var = ms_var_ptr_get(context, name)) != NULL)
		{
			ms_setenv_exists(&var, value, &name);
			i++;
			continue ;
		}
		var = ms_env_lstadd(context, argv[i++]);
		free(name);
		free(value);
	}
	return (0);
}
