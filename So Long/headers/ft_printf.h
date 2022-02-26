/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:52:47 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/06 14:54:25 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define DEX "0123456789"
# define U_I unsigned int
# define U_L unsigned long
# define SIZE_SUB_FLAGS 50

int		ft_printf(const char *txt, ...);
char	*read_flags(char *txt, va_list	*args, int *len_read);
int		read_text(char *txt, va_list	*args);
int		read_args(char *text);
// PRINT
int		str_to_int(char **v, int n);
int		print_base_int(char *base, int n);
int		print_base_unsigned(char *base, unsigned int n);
int		print_base_long(char *base, unsigned long n);
int		print_char(va_list	*args);
int		print_str(va_list	*args);
int		print_unsigned(char *base, unsigned int n);
#endif
