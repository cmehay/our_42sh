/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/01/20 18:06:04 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/05 15:46:25 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

static void	change_env_struct(char *var, t_env *env)
{
	char	*name;
	char	*value;

	name = ms_var_name_get(var);
	value = ms_var_value_get(var);
	value = (value) ? value : cool_strnew(0);
	if (ft_strequ(name, env->name))
	{
		cool_free(env->value);
		env->value = value;
	}
	else
	{
		env->next = (t_env*)cool_malloc(sizeof(t_env));
		env->next->name = name;
		env->next->value = value;
		env->next->prev = env;
	}
}

t_bool	change_env(t_command *cmd)
{
	char	**argv;
	t_env	*env;
	t_env	*lst;
	t_bool	flag;

	flag = TRUE;
	argv = cmd->argv;
	env = cmd->env_cpy;
	while (is_a_var_set(*(++argv)))
	{
		lst = env;
		while (lst->next && lst->name
			&& ft_strcmp(lst->name, ms_var_name_get(*argv)))
			lst = lst->next;
		change_env_struct(*argv, lst);
		flag = FALSE;
	}
	if (++argv && *argv)
		return (flag);
	return (FALSE);
}

static int	set_shift(char **argv)
{
	int	rtn;
	int	i;

	rtn = 1;
	i = 0;
	while (argv[++i] && is_a_var_set(argv[i]))
		rtn++;
	if (argv[i])
		return (rtn);
	return (0);
}

int			ms_builtin_env(t_context *context, char **argv, int outfd)
{
	t_env	*current;
	int		shift;

	current = context->env;
	if (argv[1] && (ft_strequ(argv[1], "-i") || ft_strequ(argv[1], "-")))
	{
		if (argv[2])
			return (2);
		else
			return (ms_err_ret("Usage: env -i cmd", 0));
	}
	if (argv[1] && is_a_var_set(argv[1]))
	{
		if (!(shift = set_shift(argv)))
			return (ms_err_ret("Usage: env <name>=<value> cmd", 0));
		return (shift);
	}
	while (current)
	{
		ft_putstr_fd(current->name, outfd);
		ft_putchar_fd('=', outfd);
		ft_putendl_fd(current->value, outfd);
		current = current->next;
	}
	return (0);
}
