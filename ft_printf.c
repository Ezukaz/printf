/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:10:45 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/15 20:08:49 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

// !!ft_strchr("cspdiuxX%", c);
static int	isset(const char c)
{
	return (ft_strchr("cspdiuxX%", c) != NULL);
}

static int	call_specifier_fn(const unsigned char c, va_list ap)
{
	static fn_lookup_t	funcs[256];
	static int			flag;

	if (c == '%')
		return (write(1, "%", 1));
	if (!flag)
	{
		funcs['c'] = put_c;
		funcs['s'] = put_s;
		funcs['p'] = print_p;
		funcs['d'] = put_signed;
		funcs['i'] = put_signed;
		funcs['u'] = put_unsigned;
		funcs['x'] = print_x;
		funcs['X'] = print_X;
		flag = 1;
	}
	return (funcs[c](ap));
}
//Unknown format will print '%' + char
static int	print_flagged(const char c, va_list ap)
{
	int	n;

	n = 0;
	if (isset(c))
		return (call_specifier_fn(c, ap));
	n += write(1, "%", 1);
	n += write(1, &c, 1);
	return (n);
}

static int	count_printed(const char *format, va_list ap)
{
	int	i;
	int	j;
	int flag;
	int tmp;

	i = 0;
	j = 0;
	flag = 0;
	while (format[i] != '\0')
	{
		if (flag)
		{
			tmp = print_flagged(format[i], ap);
			if (tmp == PRINT_ERR)
				return (PRINT_ERR);
			j += tmp;
		}
		if (format[i] == '%' || flag)
		{
			flag ^= 1;
			i++;
			continue ;
		}
		j += write(1, &format[i++], 1);
	}
	if (i != 0 && format[i - 1] == '%')
		j += write(1, "%", 1);
	return (j);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		n;

	va_start(args, format);
	n = count_printed(format, args);
	if (n == PRINT_ERR)
		return (PRINT_ERR);
	va_end(args);
	return (n);
}

	// while (format[i] != '\0')
	// {
	// 	if (flag)
	// 	{
	// 		tmp = print_flagged(format[i], args);
	// 		if (tmp == PRINT_ERR)
	// 			return (PRINT_ERR);
	// 		j += tmp;
	// 	}
	// 	if (format[i] == '%' || flag)
	// 	{
	// 		flag ^= 1;
	// 		i++;
	// 		continue ;
	// 	}
	// 	j += write(1, &format[i++], 1);
	// }
	// if (i != 0 && format[i - 1] == '%')
	// 	j += write(1, "%", 1);
	