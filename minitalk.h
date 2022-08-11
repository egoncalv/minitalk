/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:49:57 by erickbarros       #+#    #+#             */
/*   Updated: 2022/08/11 03:07:55 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "ft_printf/includes/ft_printf.h"

void	str_convert(int num, int server_pid);
void	handle_sig(int sig);
void	handle_bits(int bit);
void	byte_convert(int byte);
void	exit_error(char *message);

#endif
