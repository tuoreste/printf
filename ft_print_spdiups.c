/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spdiups.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:03:15 by otuyishi          #+#    #+#             */
/*   Updated: 2023/05/21 19:31:05 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		ft_put_str("(null)");
		return (6);
	}
	while (str[len] != '\0')
	{
		write (1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_print_ptr(uintptr_t p)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (p == 0)
		len += write(1, "0", 1);
	else
	{
		ft_insert_ptr(p);
		while (p != 0)
		{
			len ++;
			p /= 16;
		}
	}
	return (len);
}

int	ft_print_digint(int nbr)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(nbr);
	len = ft_print_str(str);
	free(str);
	return (len);
}

int	ft_print_udeci(unsigned int i)
{
	char			c;
	unsigned int	count;

	count = 0;
	if (i == 2147483647)
	{
		write (1, "2147483647", 10);
		return (10);
	}
	else if (i <= 9)
	{
		c = i + '0';
		write(1, &c, 1);
		count++;
	}
	else
	{
		count += ft_print_udeci(i / 10);
		c = i % 10 + '0';
		write (1, &c, 1);
		count++;
	}
	return (count);
}

int	ft_put_percent(void)
{
	write(1, "%", 1);
	return (1);
}
