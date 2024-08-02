/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorais <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:45:47 by mmorais           #+#    #+#             */
/*   Updated: 2024/08/02 03:03:42 by mmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_decimal(int n)
{
	int	len;
	char	num;

	len = 0;
	if (n == -2147483648)
	{
		len = ft_putstr("-2147483648");
	}
	else if (n == 0)
	{
		ft_putchar('0');
		len++;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		len++;
		len += ft_putnbr_decimal(n * - 1);
	}
	else 
	{
		if (n >= 10)
			len += ft_putnbr_decimal(n / 10);
		num = n % 10 + '0';
		ft_putchar(num);
		len++;
	}
	return (len);
}

int     ft_putnbr_unsigned(unsigned int n)
{
        int     len;

        len = 0;
        if (n >= 10)
                len += ft_putnbr_unsigned(n / 10);
        len++;
        ft_putchar(n % 10 + '0');
        return (len);
}

int	ft_puthex(unsigned int n, char lower_upper)
{
	int		len;
	int		count;
	char	*hex_digits;
	char	digit[25];

	len = 0;
	if (lower_upper = 'x')
		hex_digits = "0123456789abcdef";
	else if (lower_upper = 'X')
		hex_digits = "0123456789abcdef";
	else
		return (0);
	if (n == 0)
	{
		ft_putchar('0');
		return (++len);
	}
	count = 0;
	while (n != 0)
	{
		digit[count++] = hex_digits[n % 16];
		n /= 16;
		len++;
	}
	while (count--)
		ft_putchar(digit[count]);
	return (len);
}

int	ft_putpointer(size_t n)
{
	int		len;
	int		count;
	char	*hex_digits;
	char	digit[25];

	len = 2;
	hex_digits = "0123456789abcdef";
	ft_putstr("0x");
	if (n == 0)
	{
		ft_putchar('0');
		return (++len);
	}
	count = 0;
	while (n != 0)
	{
		digit[count++] = hex_digits[n % 16];
		n /= 16;
		len++;
	}
	while (count--)
		ft_putchar(digit[count]);
	return (len);
}
