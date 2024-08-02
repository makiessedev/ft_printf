/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorais <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:45:38 by mmorais           #+#    #+#             */
/*   Updated: 2024/08/02 06:36:42 by mmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *placeholder, ...);
int		ft_putnbr_decimal(int n);
int		ft_putstr(char *str);
int		ft_putnbr_decimal(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_puthex(unsigned int n, char lower_upper);
int		ft_putpointer(size_t n);
void	ft_putchar(char c);
#endif
