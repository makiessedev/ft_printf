/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorais <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:11:14 by mmorais           #+#    #+#             */
/*   Updated: 2024/08/05 15:24:11 by mmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_switch(char type, va_list *arg, int *len, int *count);

int	ft_printf(const char *placeholder, ...)
{
	int		count;
	int		len;
	va_list	args;

	len = 0;
	count = 0;
	va_start(args, placeholder);
	while (placeholder[count])
	{
		if (placeholder[count] == '%')
		{
			count++;
			ft_switch(placeholder[count], &args, &len, &count);
			count++;
		}
		else
		{
			ft_putchar(placeholder[count++]);
			len++;
		}
	}
	va_end(args);
	return (len);
}

static void	ft_switch(char type, va_list *arg, int *len, int *count)
{
	if (type == 'c')
	{
		ft_putchar(va_arg(*arg, int));
		(*len)++;
	}
	else if (type == 's')
		*len += ft_putstr(va_arg(*arg, char *));
	else if (type == 'p')
		*len += ft_putpointer(va_arg(*arg, size_t));
	else if (type == 'd')
		*len += ft_putnbr_decimal(va_arg(*arg, int));
	else if (type == 'i')
		*len += ft_putnbr_decimal(va_arg(*arg, int));
	else if (type == 'u')
		*len += ft_putnbr_unsigned(va_arg(*arg, unsigned int));
	else if (type == 'x')
		*len += ft_puthex(va_arg(*arg, unsigned int), 'x');
	else if (type == 'X')
		*len += ft_puthex(va_arg(*arg, unsigned int), 'X');
	else if (type == '%')
	{
		write(1, "%", 1);
		(*len)++;
	}
	else
		(*count)--;
}
