/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:03:57 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/16 11:54:20 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int	verify_add(int count, int write_res)
{
	if (write_res == PRINT_ERR)
		return (PRINT_ERR);
	return (write_res + count);
}

/*
POINTERS:
Is long safe? What is it for?

Long is not for INT_MIN overflow. Unsigned will handle that just fine. It is for
64-bit systems that have addresses that cannot fit in an int
This is safe because in a 64-bit system, long means long. Long only means int on
32-bit systems, and the addresses will fit in int, as well
65 for the max string size of a long
*/

int	print_unsigned_base(unsigned long ul, const char *base_chars)
{
	size_t	base;
	char	buf[65];
	int		i;
	int		char_count;

	if (!base_chars || base_chars[0] == '\0' || base_chars[1] == '\0')
		return (PRINT_ERR);
	base = ft_strlen(base_chars);
	i = 64;
	buf[i--] = '\0';
	if (ul == 0)
		buf[i--] = base_chars[0];
	while (ul > 0)
	{
		buf[i--] = base_chars[ul % base];
		ul /= base;
	}
	i++;
	char_count = 64 - i;
	return (write(1, buf + i, char_count));
}

/*
Pointers:
Check for 0
unsigned int for int_min overflow

The safety measure is the int being cast to unsigned.
Signed is not safe because if it overflows it is ub.
Its not that unsigned is safe (well, actually it is because we can predict
what it will do, unlike signed)
Then why is signed ub? They could've made it predictable like unsigned and
make it always wrap around. My theory is that the signed mark is causing the
ruckus. It is not part of the number. That is what is different from signed and
unsigned
*/

// int	put_nbr(int d)
// {
// 	int				char_count;
// 	int				i;
// 	unsigned int	ud;
// 	char			s[12];

// 	i = 11;
// 	s[i--] = '\0';
// 	ud = (unsigned int)d;
// 	while (ud > 0)
// 	{
// 		s[i--] = ud % 10 + '0';
// 		ud /= 10;
// 	}
// 	if (d == 0)
// 		s[i--] = '0';
// 	if (d < 0)
// 		s[i--] = '-';
// 	i++;
// 	char_count = 10 - i;
// 	return (write(1, s + i, char_count));
// }
