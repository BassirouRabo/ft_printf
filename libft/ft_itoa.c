/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:42:19 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/20 03:01:09 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	char	*p1;
	char	*p2;
	char	temp;

	if (!str || !*str)
		return (str);
	p1 = str;
	p2 = str + ft_strlen(str) - 1;
	while (p2 > p1)
	{
		temp = *p2;
		*p2 = *p1;
		*p1 = temp;
		++p1;
		--p2;
	}
	return (str);
}

static int	words(int n)
{
	int c;

	c = (n < 0) ? 2 : 1;
	while (n && (n /= 10))
		c++;
	return (c);
}

static int	words_uintmax_t(uintmax_t n)
{
	uintmax_t c;

	while (n && (n /= 10))
		c++;
	return (c);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		neg;
	int		index;

	index = 0;
	ret = ft_strnew(words(n));
	if (!ret)
		return (NULL);
	neg = (n < 0) ? 1 : 0;
	while (n)
	{
		ret[index++] = (n % 10 > 0) ? (n % 10 + '0') : (n % 10 * (-1) + '0');
		n /= 10;
	}
	if (neg)
		ret[index++] = '-';
	if (ret[0] == 0)
		ret[0] = '0';
	return (ft_strrev(ret));
}

static int	words_s(long long  n)
{
	long long  c;

	while (n && (n /= 10))
		c++;
	return (c);
}

char		*ft_itoa_s(long long n)
{
	char	*ret;
	long long		neg;
	int		index;

	printf("");
	index = 0;
	ret = ft_strnew(words_s(n));
	if (!ret)
		return (NULL);
	neg = (n < 0) ? 1 : 0;
	while (n)
	{
		ret[index++] = (n % 10 > 0) ? (n % 10 + '0') : (n % 10 * (-1) + '0');
		n /= 10;
	}
	if (neg)
		ret[index++] = '-';
	if (ret[0] == 0)
		ret[0] = '0';
	return (ft_strrev(ret));
}

char		*ft_itoa_uintmax_t(uintmax_t n)
{
	char		*ret;
	uintmax_t	neg;
	uintmax_t	index;

	index = 0;
	ret = ft_strnew(words_uintmax_t(n));
	if (!ret)
		return (NULL);
	while (n)
	{
		ret[index++] = (n % 10 > 0) ? (n % 10 + '0') : (n % 10 * (-1) + '0');
		n /= 10;
	}
	if (ret[0] == 0)
		ret[0] = '0';
	return (ft_strrev(ret));
}

static int	words_u(unsigned long long n)
{
	unsigned long long	c;

	while (n && (n /= 10))
		c++;
	return (c);
}

char		*ft_itoa_u(unsigned long long n)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strnew(words_u(n));
	if (!ret)
		return (NULL);
	while (n)
	{
		ret[i++] = (n % 10 > 0) ? (n % 10 + '0') : (n % 10 * (-1) + '0');
		n /= 10;
	}
	if (ret[0] == 0)
		ret[0] = '0';
	return (ft_strrev(ret));
}

