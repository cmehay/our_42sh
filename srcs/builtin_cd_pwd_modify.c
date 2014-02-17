/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_pwd_modify.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:47:40 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/17 18:56:13 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <stdlib.h>
#include <unistd.h>

int	ms_builtin_cd_pwd_oldpwd_modify(t_context *context, char **old_pwd)
{
	t_env	*current;

	if ((current = ms_var_ptr_get(context, "OLDPWD")) == NULL)
	{
		free(*old_pwd);
		return (ms_err_ret("cd: variable 'OLDPWD' unset", 1));
	}
	free(current->value);
	current->value = *old_pwd;
	if ((current = ms_var_ptr_get(context, "PWD")) == NULL)
		return (ms_err_ret("cd: variable 'PWD' unset", 1));
	free(current->value);
	current->value = getcwd(NULL, 0);
	return (0);
}
