/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:07:14 by mm-furi           #+#    #+#             */
/*   Updated: 2024/10/18 18:13:56 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str, int *res)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	*res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*res *= 10;
		*res += str[i] - '0';
		i++;
	}
	return (1);
}
