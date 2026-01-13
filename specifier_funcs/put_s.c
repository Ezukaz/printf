/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:23:02 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/13 17:12:56 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	put_s(va_list ap)
{
	char	*s;
	int		n;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	if ((n = write(1, s, ft_strlen(s))) < 0)
		return (WRITE_ERR);
	return (n);
}
