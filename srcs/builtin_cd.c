/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 17:00:03 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/01 17:41:28 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/stat.h>

static int	ms_cd_home(t_context *context)
{
	t_env	*home_pwd;

	if ((home_pwd = ms_var_ptr_get(context, "HOME")) == NULL)
		return (ms_err_ret("cd: variable 'HOME' unset", 1));
	if (!(chdir(home_pwd->value) == 0))
		return (ms_err_ret("cd: value in 'HOME' is wrong", 1));
	return (0);
}

static int	ms_cd_less(t_context *context)
{
	t_env	*old_pwd;

	if ((old_pwd = ms_var_ptr_get(context, "OLDPWD")) == NULL)
		return (ms_err_ret("cd: variable 'OLDPWD' unset", 1));
	if (!(chdir(old_pwd->value) == 0))
		return (ms_err_ret("cd: value in 'OLDPWD' is wrong", 1));
	return (0);
}

static int	ms_cd_full_path(char **argv)
{
	struct stat	st_path;

	if (stat(argv[1], &st_path) == 0)
	{
		if (st_path.st_mode & S_IFDIR)
		{
			if (chdir(argv[1]) == -1)
				return (ms_err_ret("cd: bad permissions", 2));
			return (0);
		}
		else
			return (ms_err_ret("cd: not a directory", 2));
	}
	return (1);
}

static int	ms_cd_path(t_context *context, char **argv)
{
	char		*path;
	struct stat	st_path;
	t_env		*pwd_pwd;

	if ((pwd_pwd = ms_var_ptr_get(context, "PWD")) == NULL)
		return (ms_err_ret("cd: variable 'PWD' unset", 1));
	path = ft_strjoinpath(pwd_pwd->value, argv[1]);
	if (path == NULL)
		return (ms_err_ret("cool_malloc failed", 1));
	if (stat(path, &st_path) == -1)
		return (ms_err_ret("cd: no such file or directory", 1));
	if (st_path.st_mode & S_IFDIR)
	{
		if (chdir(path) == -1)
			return (ms_err_ret("cd: bad permissions", 1));
		return (0);
	}
	else
		return (ms_err_ret("cd: not a directory", 1));
	return (-1);
}

int			ms_builtin_cd(t_context *context, char **argv, int __UNUSED__ outfd)
{
	int		ret;
	char	*old_pwd;

	old_pwd = getcwd(NULL, 0);
	if (argv[1] == NULL)
		ret = ms_cd_home(context);
	else
	{
		if (ft_strcmp(argv[1], "-") == 0)
			ret = ms_cd_less(context);
		else
		{
			ret = ms_cd_full_path(argv);
			if (ret == 1)
				ret = ms_cd_path(context, argv);
		}
	}
	if (ret == 0)
		ret = ms_builtin_cd_pwd_oldpwd_modify(context, &old_pwd);
	else
		cool_free(old_pwd);
	return (ret);
}
