/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:10:45 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/13 12:27:44 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isset(const char c)
{
	int					i;
	const char	*conv_c[9];

	i = 0;
	conv_c = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%', '\0'};
	while (conv_c[i] != '\0')
	{
		if (conv_c[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	call_specifier_fn(const unsigned char c, va_)
{
	static fn_lookup	funcs[9];
	static int				flag;

	if (!flag)
	{
		funcs['c'] = ;
		funcs['s'] = ;
		funcs['p'] = ;
		funcs['d'] = ;
		funcs['i'] = ;
		funcs['u'] = ;
		funcs['x'] = ;
		funcs['X'] = ;
		funcs['%'] = ;
		flag = 1;
	}
	return (funcs[c](va_));
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
	return (i + 1);
}
