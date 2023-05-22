/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:23:38 by otuyishi          #+#    #+#             */
/*   Updated: 2023/05/21 13:36:27 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_insert_ptr(uintptr_t p)
{
	if (p <= 9)
		ft_putchar_fd((p + '0'), 1);
	else if (p >= 16)
	{
		ft_insert_ptr(p / 16);
		ft_insert_ptr(p % 16);
	}
	else
		ft_putchar_fd((p - 10 + 'a'), 1);
}
