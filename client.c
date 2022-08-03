/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:49:59 by erickbarros       #+#    #+#             */
/*   Updated: 2022/08/03 14:40:23 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main (int argc, char *argv[])
{
	int	server_pid;

	server_pid = argv[1];
	if (argc != 3)
	{
		ft_printf("Please inform the server's PID and a string\n");
		return (0);
	}	
		ft_printf("Connection established to process %d\n", server_pid);
	kill(server_pid, 9);
}
