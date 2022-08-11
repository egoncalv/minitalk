/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:49:51 by erickbarros       #+#    #+#             */
/*   Updated: 2022/08/11 20:00:31 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	newhandler;

	newhandler.__sigaction_u.__sa_handler = &handle_sig;
	newhandler.sa_flags = 0;
	sigemptyset(&(newhandler.sa_mask));
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &newhandler, NULL);
	sigaction(SIGUSR2, &newhandler, NULL);
	while (1)
		pause();
}

void	handle_sig(int sig)
{
	if (sig == SIGUSR1)
		handle_bits(0);
	if (sig == SIGUSR2)
		handle_bits(1);
}

void	handle_bits(int bit)
{
	static int	n;
	static int	byte;

	if (n == 8)
	{
		byte_convert(byte);
		n = 0;
		byte = 1;
	}
	if (bit == 0)
		byte *= 10;
	if (bit == 1)
		byte = (byte * 10) + 1;
	n++;
}

void	byte_convert(int byte)
{
	int	last_bit;
	int	dec;
	int	i;

	i = 0;
	dec = 0;
	while (byte > 0)
	{
		last_bit = byte % 10;
		dec += last_bit << i;
		byte /= 10;
		i++;
	}
	write(1, &dec, 1);
}
