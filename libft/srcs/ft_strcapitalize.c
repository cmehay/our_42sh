/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/20 22:01:38 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/03 14:26:01 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	str[i] -= 32;
	while (str[i] != '\0')
	{
		if (str[i - 1] < 65
		|| (str[i - 1] > 90
		&& str[i - 1] < 97) || str[i - 1] > 122)
			if (str[i] > 96 && str[i] < 123
			&& (str[i - 1] < 48 || str[i - 1] > 57))
				str[i] -= 32;
		i++;
	}
	return (str);
}