/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/01/20 18:06:04 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/04 23:23:55 by cmehay           ###   ########.fr       */
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

static void	ms_setenv_exists(t_env *var, char *value, char **name)
{
	cool_free(var->value);
	var->value = value;
	cool_free(*name);
}

int			ms_builtin_setenv(t_context *context, char **argv, int outfd)
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
		if (!name || !ft_strcmp(name, "=") || !value)
			return (ms_err_ret("Usage: setenv <name>=<value> ...", 1));
		if ((var = ms_var_ptr_get(context, name)) != NULL)
		{
			ms_setenv_exists(var, value, &name);
			i++;
			continue ;
		}
		var = ms_env_lstadd(context, argv[i++]);
		cool_free(name);
		cool_free(value);
	}
	return (0);
}
