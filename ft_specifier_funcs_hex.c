/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_funcs_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:24:32 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/15 18:37:09 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(va_list ap)
{
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	return (print_unsigned_base((unsigned long)d, HEX_LOWER));
}

int	print_X(va_list ap)
{
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	return (print_unsigned_base((unsigned long)d, HEX_UPPER));
}

/*
uintptr_t will cast to the correct type. If 64-bit then long, if 32-bit then int
_t is the suffix for type. I'll keep that in mind when naming types
*/

int	print_p(va_list ap)
{
	void	*p;
	int		n;
	int		tmp;

	p = va_arg(ap, void *);
	if (!p)
		return (write(1, "(nil)", 5));
	n = write(1, "0x", 2);
	tmp = print_unsigned_base((uintptr_t)p, HEX_LOWER);
	if (tmp == PRINT_ERR)
		return (PRINT_ERR);
	return (n + tmp);
}
