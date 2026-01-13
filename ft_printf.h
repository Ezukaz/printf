/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:12:49 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/13 12:28:26 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_F_H
# define PRINT_F_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef int (*fn_lookup)(int);

int	ft_printf(const char *, ...);

#endif
