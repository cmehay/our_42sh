/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_lookup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 01:33:05 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/25 03:04:28 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static char	*replace_vars(char *str, char *varname, t_context *context)
{
	char	*var_content;
	char	*var_name;
	char	*rtn;

	if (!(var_content = find_var(varname, context)))
		return (str);
	var_name = cool_strjoin("$", varname);
	rtn = ft_strrep(var_name, var_content, str);
	cool_free(str);
	cool_free(var_name);
	return (rtn);
}

char		*looking_for_vars(char *str, t_context *context)
{
	char	**var_split;
	char	*rtn;
	int		i;
	int		j;

	rtn = str;
	if (!str)
		return (NULL);
	var_split = cool_strsplit(str, '$');
	if (var_split[0] && var_split[1])
	{
		i = 0;
		while (var_split[++i])
		{
			j = -1;
			while (var_split[i][++j])
			{
				if (!ft_isalpha(var_split[i][j]))
					var_split[i][j] = 0;
			}
			rtn = replace_vars(rtn, var_split[i], context);
		}
	}
	cool_arraydel(var_split);
	return (rtn);
}
