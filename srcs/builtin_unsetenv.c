/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 12:44:23 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/26 22:43:12 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int	ms_builtin_unsetenv(t_context *context, char **argv,
		int __UNUSED__ outfd)
{
	t_env	*var;
	t_env	*var_next;
	int		i;

	if (argv[1] == NULL)
		return (ms_err_ret("Usage: unsetenv <name> ...", 1));
	i = 1;
	while (argv[i])
	{
		if ((var = ms_var_ptr_get(context, argv[i])) == NULL)
		{
			i++;
			continue ;
		}
		var_next = var->next;
		if (var == context->env)
			context->env = var_next;
		ms_env_lstdelone(&var);
		i++;
		continue ;
	}
	return (0);
}
