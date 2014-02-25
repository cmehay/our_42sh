/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 21:49:33 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/25 01:59:17 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

t_bool	is_a_var_set(char *str)
{
	int	i;

	i = -1;
	if (str && *str == '=')
		return (_FALSE);
	while (str && str[++i])
	{
		if (i > 0 && str[i] == '=')
		{
			if (ft_isalpha(str[i - 1]) && ft_isalpha(str[i + 1]))
				return (_TRUE);
		}
	}
	return (_FALSE);
}

t_bool	is_a_var(char *str)
{
	if (str && *str == '$')
	{
		while (str && *(str + 1))
		{
			if (!ft_isalpha(*(++str)))
				return (_FALSE);
		}
		return (_TRUE);
	}
	return (_FALSE);
}

char	*find_var(char *var, t_context *context)
{
	t_env	*current;

	current = context->env;
	while (current)
	{
		if (ft_strequ(current->name, var))
			return (current->value);
		current = current->next;
	}
	return (find_local_var(var));
}

int		ms_builtin_setvar(t_context *context, char **argv, int __UNUSED__ outfd)
{
	char	**vars;
	t_env	*current;

	current = context->env;
	vars = cool_strsplit(argv[0], '=');
	while (current)
	{
		if (ft_strequ(current->name, vars[0]))
		{
			cool_free(current->value);
			current->value = vars[1];
			return (0);
		}
		current = current->next;
	}
	add_local_var(vars[0], vars[1]);
	return (0);
}

int		ms_builtin_export(t_context *context, char **argv, int __UNUSED__ outfd)
{
	char	*tmp;
	char	*tmp2;
	char	*var;

	if ((var = find_local_var(argv[1]))
	{
		tmp = cool_strjoin(argv[1], '=');
		tmp2 = cool_strjoin(tmp, var);
		rm_local_var(argv[1]);
		cool_free(argv[1]);
		argv[1] = tmp2;
		cool_free(tmp);
		return (ms_builtin_setenv(context, argv, outfd));
	}
	if (!argv[1] || is_a_var_set(argv[1]))
		return (ms_builtin_setenv(context, argv, outfd));
	return (0);
}
