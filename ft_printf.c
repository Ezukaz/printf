/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:10:45 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/16 01:14:33 by Ezukaz           ###   ########.fr       */
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
	if (isset(c))
		return (call_specifier_fn(c, ap));
	if (write(1, "%", 1) == PRINT_ERR)
		return (PRINT_ERR);
	if (write(1, &c, 1) == PRINT_ERR)
		return (PRINT_ERR);
	return (2);
}

static int	write_count(const int flag, const char c, va_list ap, int count)
{
	int	tmp;

	if (flag)
	{
		tmp = print_flagged(c, ap);
		if (tmp == PRINT_ERR)
			return (PRINT_ERR);
		return (tmp + count);
	}
	tmp = write(1, &c, 1);
	if (tmp == PRINT_ERR)
		return (PRINT_ERR);
	return (tmp + count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		count = write_count(flag, format[i], args, count);
		if (count == PRINT_ERR)
			return (PRINT_ERR);
		if (format[i] == '%' || flag)
			flag ^= 1;
		i++;
	}
	va_end(args);
	if (flag)
		return (write_count(0, '%', args, count));
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
	