/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:20 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/24 12:07:55 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

int	main(int __UNUSED__ argc, char __UNUSED__ **argv, char **environ)
{
	t_context	*context;

	ms_signal_catch();
	context = ms_context_get();
	if (context == NULL)
		return (-1);
	ms_context_init(context);
	context = ms_context_fill(context, environ);
	if (context == NULL)
		return (-1);
	ms_prompt_run(context);
	ms_context_clean(context);
	return (0);
}
