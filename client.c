/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:49:59 by erickbarros       #+#    #+#             */
/*   Updated: 2022/09/10 15:30:41 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	i;

	i = 0;
	if (argc != 3)
		exit_error("Please inform the server´s PID and a string");
	server_pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		str_convert(argv[2][i], server_pid);
		i++;
	}
	str_convert('\n', server_pid);
}

void	str_convert(int num, int server_pid)
{
	int	i;
	int	k;

	i = 7;
	while (i >= 0)
	{
		k = num >> i;
		if (k & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		i--;
		usleep(100);
	}
}

void	exit_error(char *message)
{
	ft_printf("%s\n", message);
	exit(0);
}
