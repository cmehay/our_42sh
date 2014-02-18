/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/01/20 17:37:25 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 20:18:49 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static char	**ms_paths_get(t_env __UNUSED__ *env, char *cmd)
{
	t_env	*path;
	char	**paths;

	if ((path = ms_var_ptr_get(ms_context_get(), "PATH")))
	{
		paths = cool_strsplit(path->value, ':');
		if (paths == NULL)
			return ((char **) ms_function_failed("cool_malloc failed", NULL));
		return (paths);
	}
	ms_command_not_found(cmd);
	return (NULL);
}

int			ms_builtins_search_exec(t_context *context, char **argv, int outfd)
{
	if (ft_strcmp("cd", argv[0]) == 0)
	{
		ms_builtin_cd(context, argv, outfd);
		return (0);
	}
	if (ft_strcmp("history", argv[0]) == 0)
		return (ms_builtin_history(context));
	if (ft_strcmp("echo", argv[0]) == 0)
		return (ms_builtin_echo(argv));
	if (ft_strcmp("setenv", argv[0]) == 0)
	{
		ms_builtin_setenv(context, argv, outfd);
		return (0);
	}
	if (ft_strcmp("unsetenv", argv[0]) == 0)
	{
		ms_builtin_unsetenv(context, argv, outfd);
		return (0);
	}
	if (ft_strcmp("env", argv[0]) == 0)
	{
		ms_builtin_env(context, argv, outfd);
		return (0);
	}
	if (ft_strcmp("exit", argv[0]) == 0)
		ms_builtin_exit(context, argv, outfd);
	return (-1);
}

static void	ms_command_paths_clean(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		cool_free(paths[i++]);
	cool_free(paths);
}

char		*ms_command_search(t_context *context, char *cmd)
{
	char	**paths;
	size_t	i;
	char	*exe;

	if (!access(cmd, F_OK | X_OK))
		return (cool_strdup(cmd));
	if ((paths = ms_paths_get(context->env, cmd)) == NULL)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		exe = ft_strjoinpath(paths[i++], cmd);
		if (exe && !access(exe, F_OK | X_OK))
		{
			ms_command_paths_clean(paths);
			return (exe);
		}
		cool_free(exe);
	}
	ms_command_paths_clean(paths);
	ms_command_not_found(cmd);
	return (NULL);
}
