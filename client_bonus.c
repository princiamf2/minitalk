/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:56:44 by mm-furi           #+#    #+#             */
/*   Updated: 2024/10/21 13:24:43 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	shift;
	int	i;

	i = 7;
	while (i >= 0)
	{
		shift = 1 << (i);
		if (c & shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, str[i]);
}

void	sighandler(int sig)
{
	(void)sig;
	ft_putstr("le message est bien arrivé\n");
}

int	send(int pid, char *str)
{
	if (kill(pid, 0) == -1)
	{
		ft_putstr("le pid n'est pas valable\n");
		return (1);
	}
	else
	{
		if (pid == 0)
		{
			ft_putstr("le pid n'est pas valable\n");
			return (1);
		}
		send_message(pid, str);
		return (0);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (1);
	signal(SIGUSR1, sighandler);
	if (ft_atoi(av[1], &pid) == 0)
	{
		ft_putstr("les arguments ne sont valable");
		return (1);
	}
	else
		return (send(pid, av[2]));
}
