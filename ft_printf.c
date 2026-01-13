/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:10:45 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/13 17:03:13 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isset(const char c)
{
	return (!!ft_strchr("cspdiuxX%", c));
}

static int	call_specifier_fn(const unsigned char c, va_list ap)
{
	static fn_lookup	funcs[256];
	static int				flag;

	if (c == '%')
		return (write(1, "%", 1));
	if (!flag)
	{
		funcs['c'] = put_s;
		funcs['s'] = put_s;
		funcs['p'] = put_address;
		funcs['d'] = put_nbr;
		funcs['i'] = put_nbr;
		funcs['u'] = put_nbr;
		funcs['x'] = put_hex;
		funcs['X'] = put_hex;
		flag = 1;
	}
	return (funcs[c](ap));
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				j;
	int				flag;
	fn_lookup	f;
	va_list		args;

	i = 0;
	j = 0;
	flag = 0;
	while (format[i] != '\0')
	{
		if (flag)
		{
			if (isset(format[i]))
				j += call_specifier_fn(format[i], );
			else
			{
				j += write(1, "%", 1);
				j += write(1, &format[i], 1);
			}
			i++;
			flag = 0;
			continue ;
		}
		if (format[i] == '%')
		{
			flag = 1;
			continue ;
		}
		write(1, format[i], 1);
		i++;
	}
	if (i != 0 && format[i - 1] == '%')
		j += write(1, "%", 1);
	return (i + j);
}
