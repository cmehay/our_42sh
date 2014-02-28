/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 03:13:29 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/25 03:20:39 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ms_builtin_unset(t_context __UNUSED__ *context, char **argv,
	int __UNUSED__ outfd)
{
	if (argv[1])
		rm_local_var(argv[1]);
	return (0);
}
