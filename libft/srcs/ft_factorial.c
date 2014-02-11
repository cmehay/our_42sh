/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/19 12:34:00 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/03 14:06:57 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_factorial(int nb)
{
	int	i;
	int	fact_nb;

	if (nb > 12)
		return (0);
	if (nb < 0)
		return (0);
	i = 2;
	fact_nb = 1;
	while (i <= nb)
		fact_nb = fact_nb * i++;
	return (fact_nb);
}
