/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taksin <taksin@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:03:13 by taksin            #+#    #+#             */
/*   Updated: 2023/09/11 12:00:50 by taksin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	return (i);
}

void	ft_sendbyte(int pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

int	main(int ac, char **av)
{
	int				pid;
	unsigned char	*str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = (unsigned char *)av[2];
		while (*str)
			ft_sendbyte(pid, *str++);
		ft_sendbyte(pid, '\n');
	}
	else
		write(1, "Error code: Check ur ARGS.(client, pid, string)", 48);
	return (0);
}
