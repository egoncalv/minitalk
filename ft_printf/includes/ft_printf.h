/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:47:17 by egoncalv          #+#    #+#             */
/*   Updated: 2022/03/30 15:28:29 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include "../libft/libft.h"

int			ft_printf(const char *input, ...);
int			ft_format_process(const char format, int count, va_list arguments);
int			ft_print_unsigned(unsigned int nbr);
int			ft_print_ptr(uintptr_t ptr);
int			ft_print_nbr(int nbr);
int			ft_convert_hex(unsigned int nbr, char format);
int			ft_convert_ptr(uintptr_t ptr);
int			ft_putchar(char c);
int			ft_putstr(char *s);
char		*ft_uitoa(unsigned int n);

#endif
