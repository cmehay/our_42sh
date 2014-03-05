/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/01/20 17:37:25 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/05 02:38:22 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

static char	**ms_paths_get(t_env *env, char *cmd)
{
	t_env	*path;
	char	**paths;

	if ((path = ms_env_get_content(env, "PATH")) && *(path->value))
	{
		paths = cool_strsplit(path->value, ':');
		if (paths == NULL)
			return ((char **) ms_function_failed("cool_malloc failed", NULL));
		return (paths);
	}
	ms_command_not_found(cmd);
	return (NULL);
}

int			ms_builtins_search_exec(t_context *context, t_command *cmd,
	int outfd)
{
	if (ft_strcmp("cd", cmd->argv[0]) == 0)
		return (ms_builtin_cd(context, cmd->argv, outfd));
	if (ft_strcmp("bg", cmd->argv[0]) == 0)
		return (ms_builtin_bg(context, cmd->argv, outfd));
	if (ft_strcmp("fg", cmd->argv[0]) == 0)
		return (ms_builtin_fg(context, cmd->argv, outfd));
	if (ft_strcmp("stop", cmd->argv[0]) == 0)
		return (ms_builtin_stop(context, cmd->argv, outfd));
	if (ft_strcmp("history", cmd->argv[0]) == 0)
		return (ms_builtin_history(context));
	if (ft_strcmp("jobs", cmd->argv[0]) == 0)
		return (ms_builtin_jobs(context, outfd));
	if (ft_strcmp("echo", cmd->argv[0]) == 0)
		return (ms_builtin_echo(context, cmd->argv, outfd));
	if (ft_strcmp("setenv", cmd->argv[0]) == 0)
		return (ms_builtin_setenv(context, cmd->argv, outfd));
	if (ft_strcmp("unsetenv", cmd->argv[0]) == 0)
		return (ms_builtin_unsetenv(context, cmd->argv, outfd));
	return (ms_builtins_search_exec2(context, cmd, outfd));
}

int			ms_builtins_search_exec2(t_context *context, t_command *cmd,
	int outfd)
{
	int	shift;

	if (ft_strcmp("env", cmd->argv[0]) == 0)
	{
		if (!(shift = ms_builtin_env(context, cmd->argv, outfd)))
			return (0);
		else
		{
			cmd->null_env = change_env(cmd);
			cool_free(cmd->argv[0]);
			cool_free(cmd->argv[1]);
			cmd->argv = cmd->argv + shift;
		}
	}
	if (ft_strcmp("exit", cmd->argv[0]) == 0)
		ms_builtin_exit(context, cmd->argv, outfd);
	if (is_a_var_set(cmd->argv[0]))
		return (ms_builtin_setvar(context, cmd->argv, outfd));
	if (ft_strcmp("export", cmd->argv[0]) == 0)
		return (ms_builtin_export(context, cmd->argv, outfd));
	if (ft_strcmp("unset", cmd->argv[0]) == 0)
		return (ms_builtin_unset(context, cmd->argv, outfd));
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

static int	ms_is_a_path(char *cmd)
{
	int	cnt;
	int	back_sl;

	back_sl = 0;
	cnt = 0;
	while (cmd[cnt])
	{
		if (back_sl == 1)
			back_sl = 0;
		else if (cmd[cnt] == '\\')
			back_sl = 1;
		else if (cmd[cnt] == '/')
			return (1);
		cnt++;
	}
	return (0);
}

char		*ms_command_search(t_env *env_cpy, char *cmd)
{
	char	**paths;
	size_t	i;
	char	*exe;

	if (ms_is_a_path(cmd) && !access(cmd, F_OK | X_OK))
		return (cool_strdup(cmd));
	if ((paths = ms_paths_get(env_cpy, cmd)) == NULL)
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
