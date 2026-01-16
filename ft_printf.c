/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:10:45 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/16 12:58:13 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

// !!ft_strchr("cspdiuxX%", c);
static int	isset(const char c)
{
	return (ft_strchr("cspdiuxX%", c) != NULL);
}

// Precondition: c must be valid (isset does the check)
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
	char	buf[2];

	if (isset(c))
		return (call_specifier_fn(c, ap));
	buf[0] = '%';
	buf[1] = c;
	return (write(1, buf, 2));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		flag_specifier;
	int		i;

	flag_specifier = 0;
	i = 0;
	va_start(args, format);
	count = 0;
	while (format[i] != '\0')
	{
		if (flag_specifier)
			count = verify_add(count, print_flagged(format[i], args));
		else if (format[i] != '%')
			count = verify_add(count, write(1, &format[i], 1));
		if (count == PRINT_ERR)
			break ;
		if (format[i] == '%' || flag_specifier)
			flag_specifier ^= 1;
		i++;
	}
	va_end(args);
	if (flag_specifier && count != PRINT_ERR)
		return (verify_add(count, write(1, "%", 1)));
	return (count);
}

// static int	count_write(const int flag, const char c, va_list ap, int count)
// {
// 	if (flag)
// 		return (verify_add(count, print_flagged(c, ap)));
// 	return (verify_add(count, write(1, &c, 1)));
// }

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
	