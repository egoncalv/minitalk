/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:49:57 by erickbarros       #+#    #+#             */
/*   Updated: 2022/09/10 17:46:14 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "ft_printf/includes/ft_printf.h"

void	str_convert(int num, int server_pid);
void	handle_sig(int sig, siginfo_t *info, void *);
void	handle_bits(int bit);
void	handler(int sig);
void	byte_convert(int byte);
void	exit_error(char *message);

#endif
