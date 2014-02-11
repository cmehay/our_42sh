/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_ret.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:03:09 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/06 17:04:04 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_err_ret(const char *msg, int errcode)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	return (errcode);
}
