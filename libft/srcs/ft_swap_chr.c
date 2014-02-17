/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 12:56:24 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/03 12:56:31 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_chr(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}