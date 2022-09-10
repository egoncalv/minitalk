/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:49:59 by erickbarros       #+#    #+#             */
/*   Updated: 2022/09/10 19:05:25 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int flag;

int	main(int argc, char *argv[])
{
	struct sigaction	newhandler;
	int	server_pid;
	int	i;

	newhandler.sa_handler = &handler;
	newhandler.sa_flags = 0;
	sigemptyset(&(newhandler.sa_mask));
	sigaction(SIGUSR1, &newhandler, NULL);
	sigaction(SIGUSR2, &newhandler, NULL);
	i = 0;
	if (argc != 3)
		exit_error("Please inform the server´s PID and a string");
	server_pid = ft_atoi(argv[1]);
	flag = 1;
	while (argv[2][i])
	{
		str_convert(argv[2][i], server_pid);
		i++;
	}
	str_convert('\0', server_pid);
	while (1)
		pause();
}

void	str_convert(int num, int server_pid)
{
	int	i;
	int	k;

	i = 7;
	while (i >= 0 && flag == 1)
	{
		k = num >> i;
		if (k & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		i--;
		flag = 0;
		usleep(50);
	}
}

void	exit_error(char *message)
{
	ft_printf("%s\n", message);
	exit(0);
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Signal Received\n");
		flag = 1;
	}
	if (sig == SIGUSR2)
		ft_printf("END\n");
}
