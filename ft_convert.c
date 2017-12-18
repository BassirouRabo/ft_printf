/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:00:14 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/18 01:18:54 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"

char	*ft_to_base(uint64_t number, int base, char bases[])
{
	uint64_t	i;
	char		*dest;
	uint64_t	nbr;

	nbr = number;
	i = 0;
	while (number > 0)
	{
		number = number / base;
		i++;
	}
	if (!(dest = ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	dest[i--] = '\0';
	while (nbr > 0)
	{
		dest[i--] = bases[(nbr % base)];
		nbr = nbr / base;
	}
	return (dest);
}

char	*ft_to_left(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (*str != ' ')
		return (str);
	if (!(dest = ft_memalloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (*str == ' ' && str++)
		i++;
	while (*str)
		dest[j++] = *str++;
	while (i-- > 0)
		dest[j++] = ' ';
	dest[j] = '\0';
	return (dest);
}

char	*ft_to_intmax_t(va_list *args, t_cs *cs)
{
	char	*out;

	out = NULL;
	if (cs->modifier2 == 'h')
		out = ft_itoa((intmax_t)va_arg(*args, int));
	if (cs->modifier1 == 'l' && cs->modifier2 == 'l')
		out = ft_itoa((intmax_t)va_arg(*args, long long));
	if ((!cs->modifier1 && cs->modifier2 == 'l') || cs->type == 'D')
		out = ft_itoa((intmax_t)va_arg(*args, long));
	if (cs->modifier2 == 'j')
		out = ft_itoa((intmax_t)va_arg(*args, intmax_t));
	if (cs->modifier2 == 'z')
		out = ft_itoa((intmax_t)va_arg(*args, size_t));
	if (!cs->modifier1 && !cs->modifier2)
		out = ft_itoa((intmax_t)va_arg(*args, int));
	return (out);
}

char	*ft_to_uintmax_t(va_list *args, t_cs *cs)
{
	char	*out;

	out = NULL;
	if (cs->modifier2 == 'h')
		out = ft_itoa((uintmax_t)va_arg(*args, unsigned int));
	if (cs->modifier1 == 'l' && cs->modifier2 == 'l')
		out = ft_itoa((uintmax_t)va_arg(*args, unsigned long long));
	if ((!cs->modifier1 && cs->modifier2 == 'l')
			|| cs->type == 'O' || cs->type == 'U')
		out = ft_itoa((uintmax_t)va_arg(*args, unsigned long));
	if (cs->modifier2 == 'j')
		out = ft_itoa((uintmax_t)va_arg(*args, uintmax_t));
	if (cs->modifier2 == 'z')
		out = ft_itoa((uintmax_t)va_arg(*args, size_t));
	if (!cs->modifier1 && !cs->modifier2)
		out = ft_itoa((uintmax_t)va_arg(*args, int));
	return (out);
}

char	*ft_cut_str(char *out, int min)
{
	int		i;
	char	*dest;

	i = 0;
	if (ft_strlen(out) <= min)
		return (out);
	if (!(dest = ft_memalloc(sizeof(char) * (min + 1))))
		return (NULL);
	while (min--)
		dest[i++] = *out++;
	dest[i] = '\0';
	free(out);
	out = NULL;
	return (dest);
}
