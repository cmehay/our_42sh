/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 20:39:10 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 22:43:14 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <stdlib.h>

int	ms_builtin_exit(t_context *context,
		char __UNUSED__ **argv, int __UNUSED__ outfd)
{
	ms_context_clean(context);
	exit (1);
}
