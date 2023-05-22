/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:43:25 by otuyishi          #+#    #+#             */
/*   Updated: 2023/05/21 14:13:33 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_insert_x(uintptr_t p, char cnvrt, int *i)
{
	if (p <= 9)
	{
		ft_putchar_fd((p + '0'), 1);
		(*i)++;
	}
	else if (p >= 16)
	{
		ft_insert_x(p / 16, cnvrt, i);
		ft_insert_x(p % 16, cnvrt, i);
	}
	else if (cnvrt == 'x')
	{
		ft_putchar_fd((p - 10 + 'a'), 1);
		(*i)++;
	}
	else if (cnvrt == 'X')
	{
		ft_putchar_fd((p - 10 + 'A'), 1);
		(*i)++;
	}
}

int	ft_print_x(uintptr_t dig, char cnvrt)
{
	unsigned int	num;
	int				i;

	i = 0;
	if (cnvrt != 'x' && cnvrt != 'X')
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(cnvrt, 1);
		return (2);
	}
	if (dig == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	num = dig;
	if (dig < 0)
	{
		ft_putchar_fd('-', 1);
		num = -dig;
		i++;
	}
	ft_insert_x(num, cnvrt, &i);
	return (i);
}

int	ft_format(va_list args, const char *format)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (*format == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (*format == 'p')
		len += ft_print_ptr(va_arg(args, uintptr_t));
	else if (*format == 'd' || *format == 'i')
		len += ft_print_digint(va_arg(args, int));
	else if (*format == 'u')
		len += ft_print_udeci(va_arg(args, unsigned long long));
	else if (*format == 'x')
		len += ft_print_x(va_arg(args, unsigned int), 'x');
	else if (*format == 'X')
		len += ft_print_x(va_arg(args, unsigned int), 'X');
	else if (*format == '%')
		len += ft_put_percent();
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			len += ft_format(args, s + 1);
			s++;
		}
		else
		{
			write(1, s, 1);
			len++;
		}
		s++;
	}
	va_end(args);
	return (len);
}
