/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:44:07 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/18 14:07:14 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	digit(char	**str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
		{
			if (!ft_isdigit(str[i][++j]))
				digit_error();
		}
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				digit_error();
			j++;
		}
		i++;
	}
}

void	digit_error(void)
{
	ft_putstr("Error : in digit\n", 2);
	exit(1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
