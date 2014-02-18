/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_key_lookup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 17:49:08 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 13:47:11 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static t_key_func_assoc	func_assoc[17] =
{
	{
		KEY_ARROW_UP,
		ms_key_is_arrow_up
	},
	{
		KEY_ARROW_DOWN,
		ms_key_is_arrow_down
	},
	{
		KEY_ARROW_RIGHT,
		ms_key_is_arrow_right
	},
	{
		KEY_ARROW_LEFT,
		ms_key_is_arrow_left
	},
	{
		KEY_SHIFT_ARROW_UP,
		ms_key_is_shift_arrow_up
	},
	{
		KEY_SHIFT_ARROW_DOWN,
		ms_key_is_shift_arrow_down
	},
	{
		KEY_SHIFT_ARROW_RIGHT,
		ms_key_is_shift_arrow_right
	},
	{
		KEY_SHIFT_ARROW_LEFT,
		ms_key_is_shift_arrow_left
	},
	{
		KEY_HOME,
		ms_key_is_home
	},
	{
		KEY_END,
		ms_key_is_end
	},
	{
		KEY_CTRL_X,
		ms_key_is_ctrl_x
	},
	{
		KEY_CTRL_Y,
		ms_key_is_ctrl_y
	},
	{
		KEY_CTRL_P,
		ms_key_is_ctrl_p
	},
	{
		KEY_CTRL_V,
		ms_key_is_ctrl_v
	},
	{
		KEY_CTRL_D,
		ms_key_is_ctrl_d
	},
	{
		KEY_BACKSPACE,
		ms_key_is_backspace
	},
	{
		0,
		NULL
	}
};

int	ms_key_lookup(t_context *ctx, uint64_t key, t_cmd_char **cmd_char)
{
	int		i;

	i = 0;
	while (func_assoc[i].key != 0)
	{
		if (func_assoc[i].key == key)
			return (func_assoc[i].fptr(ctx, cmd_char));
		i++;
	}
	return (1);
}
