/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:12:49 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/16 11:39:23 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_F_H
# define PRINT_F_H

# define PRINT_ERR -1
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define BASE_10 "0123456789"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h> // For uintptr_t

typedef int (*fn_lookup_t)(va_list);

int	ft_printf(const char *format, ...);
int	put_c(va_list ap);
int	put_s(va_list ap);
int	put_signed(va_list ap);
int	put_unsigned(va_list ap);
int	print_x(va_list ap);
int	print_X(va_list ap);
int	print_p(va_list ap);
int	print_unsigned_base(unsigned long ud, const char *base_chars);
int	verify_add(int count, int write_res);

#endif
