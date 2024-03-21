/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:36:32 by baguiar-          #+#    #+#             */
/*   Updated: 2023/12/20 11:40:09 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar_c(char c);
int	ft_putstr_s(char *s);
int	ft_putint_d_i(int num);
int	ft_putunint_u(unsigned int u);
int	ft_printf_p(unsigned long long p);
int	ft_printf_x(unsigned int num, const char fmt);

int	ft_printf(const char *format, ...);

#endif
