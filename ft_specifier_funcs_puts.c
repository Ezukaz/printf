/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_funcs_puts.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:12:56 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/15 23:50:14 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

/*
Test -191 to see what happens without unsigned char
*/

int	put_c(va_list ap)
{
	unsigned char	c;

	c = (unsigned char)va_arg(ap, int);
	return (write(1, &c, 1));
}

int	put_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen(s)));
}

/*
POINTERS:
Cast to long to avoid interger overflow, then negate it. This safely makes an
int into a positive number. We then cast it to unsigned long so we can safely
pass it to print_unsigned_base which only takes unsigned long
*/

int	put_signed(va_list ap)
{
	int				d;
	unsigned long	ul;
	int				sign;
	int				count;

	sign = 0;
	d = va_arg(ap, int);
	if (d < 0)
	{
		sign = write(1, "-", 1);
		if (sign == PRINT_ERR)
			return (PRINT_ERR);
		ul = (unsigned long)(-(long)d);
	}
	else
		ul = (unsigned long)d;
	count = print_unsigned_base(ul, BASE_10);
	if (count == PRINT_ERR)
		return (PRINT_ERR);
	return (sign + count);
}

int	put_unsigned(va_list ap)
{
	unsigned int	ud;

	ud = va_arg(ap, unsigned int);
	return (print_unsigned_base(ud, BASE_10));
}
