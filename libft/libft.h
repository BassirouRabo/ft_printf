/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 08:23:57 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/22 20:41:54 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define SED(x) (TRIM(x) || x == '\v' || x == '\r' || x == '\f')
# define TRIM(x) (x == ' ' || x == '\n' || x == '\t')

# include <unistd.h>
# include <stdlib.h>

int						ft_atoi(const char *str);
int						ft_isdigit(int c);

char					*ft_itoa_base(int value, int base);
char					*ft_itoa_base_uintmax_t(uintmax_t value, int base);
char					*ft_itoa_base_intmax_t(intmax_t value, int base);

char					*ft_itoa(int n);
char					*ft_itoa_uintmax_t(uintmax_t n);
char					*ft_itoa_u(unsigned long long n);
char					*ft_itoa_s(long long n);

void					*ft_memalloc(size_t size);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
size_t					ft_strlen(const char *s);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memset(void *b, int c, size_t len);
void					ft_putchar_fd(char c, int fd);
void					ft_putchar(char c);
char					*ft_strnew(size_t size);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strcat(char *s1, char *s2);
void					*ft_memcpy(void *dst, const void *src, size_t n);

#endif
