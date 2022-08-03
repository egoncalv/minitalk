/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:11:07 by egoncalv          #+#    #+#             */
/*   Updated: 2022/03/30 15:41:59 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_convert_hex(unsigned int nbr, char format)
{
	static int	count;

	count = 0;
	if (nbr >= 16)
		ft_convert_hex(nbr / 16, format);
	if (format == 'x')
		count += ft_putchar("0123456789abcdef"[nbr % 16]);
	if (format == 'X')
		count += ft_putchar("0123456789ABCDEF"[nbr % 16]);
	return (count);
}

int	ft_print_ptr(uintptr_t ptr)
{
	static int	count;

	count = 0;
	if (ptr >= 16)
		ft_print_ptr(ptr / 16);
	return (count += ft_putchar("0123456789abcdef"[ptr % 16]));
}

int	ft_convert_ptr(uintptr_t ptr)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	if (!ptr)
		return (count += write(1, "0", 1));
	else
		return (count += ft_print_ptr(ptr));
}
