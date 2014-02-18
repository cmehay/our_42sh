/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 17:28:08 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/22 16:49:00 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	*ms_function_failed(char *msg, void *ret)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (ret);
}

int		ms_err_ret(char *msg, int ret)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (ret);
}

void	ms_err_display(char *msg)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return ;
}

void	ms_command_not_found(char *command)
{
	ft_putstr_fd("42sh: command not found: ", STDERR_FILENO);
	ft_putendl_fd(command, STDERR_FILENO);
}
