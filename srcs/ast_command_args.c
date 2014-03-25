/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_command_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 21:52:19 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 22:30:36 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <stdlib.h>

int	ms_ast_command_args(t_command *cmd, t_lex *lexer)
{
	size_t	argv_size;
	char	**argv;
	t_lex	*current;
	int		i;

	argv_size = ms_ast_lexer_count(lexer);
	argv_size++;
	argv = (char**)cool_malloc(argv_size * sizeof(char*));
	if (!argv)
		return (-1);
	i = 0;
	current = lexer;
	while (current)
	{
		argv[i++] = current->token;
		current->token = NULL;
		current = current->next;
	}
	argv[i] = NULL;
	cmd->argv = argv;
	return (0);
}
