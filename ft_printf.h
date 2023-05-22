/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:47:22 by otuyishi          #+#    #+#             */
/*   Updated: 2023/05/21 19:27:35 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_print_x(uintptr_t dig, char cnvrt);
int		ft_print_str(char *str);
int		ft_print_ptr(uintptr_t p);
int		ft_print_digint(int nbr);
int		ft_print_udeci(unsigned int i);
int		ft_put_percent(void);
void	ft_put_str(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_insert_ptr(uintptr_t p);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int		ft_print_char(int c);

#endif
