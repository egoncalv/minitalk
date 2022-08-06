/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:49:59 by erickbarros       #+#    #+#             */
/*   Updated: 2022/08/06 04:49:20 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	i;

	server_pid = ft_atoi(argv[1]);
	i = 0;
	if (argc != 3)
	{
		ft_printf("Please inform the server's PID and a string\n");
		return (0);
	}	
	ft_printf("Connection established to process %d\n", server_pid);
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
