/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:56:41 by otuyishi          #+#    #+#             */
/*   Updated: 2023/05/19 12:43:47 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		count;
	char		*dst_dst;
	const char	*src_src;

	count = 0;
	dst_dst = (char *)dst;
	src_src = (const char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (count < n)
	{
		dst_dst[count] = src_src[count];
		count++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	s_len;
	char	*s2;

	s_len = ft_strlen(s1) + 1;
	s2 = malloc(s_len);
	if (s2 == NULL)
		return (NULL);
	return ((char *)ft_memcpy(s2, s1, s_len));
}

static int	ft_absolute_no(int no)
{
	if (no < 0)
		return (-no);
	return (no);
}

static int	ft_count_digits(int n)
{
	int	count_digits;
	int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		count_digits = 1;
	}
	else
		count_digits = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		count_digits++;
	}
	return (count_digits);
}

char	*ft_itoa(int n)
{
	int		n_digits;
	char	*str;
	size_t	len;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_digits = ft_count_digits(n);
	str = (char *)malloc((n_digits + 1) * sizeof(char));
	len = 0;
	if (!str)
		return (NULL);
	str[n_digits] = '\0';
	if (n < 0)
	{
		str[0] = '-';
	}
	while (n && n_digits--)
	{
		str[n_digits] = ft_absolute_no(n % 10) + '0';
		n = (n / 10);
	}
	return (str);
}
