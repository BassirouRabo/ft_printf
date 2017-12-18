/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 00:35:58 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/18 00:57:20 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_add_zero(char *dest, int min, int prefix)
{
	int	i;

	i = 0;
	min = prefix ? min - prefix : min;
	if (*dest != ' ')
		return (dest);
	while (dest[i] == ' ' && (i < ft_strlen(dest) - min))
		i++;
	while (dest[i] == ' ')
		dest[i++] = '0';
	return (dest);
}

char	*ft_add_prefix(char *out, char prefix1, char prefix2)
{
	int		i;
	char	*dest;

	i = 0;
	if (*out != '0' && *out != ' ')
	{
		if (!(dest = ft_memalloc(ft_strlen(out) + 1 + (prefix2 ? 1 : 0))))
			return (NULL);
		dest[i++] = prefix1;
		if (prefix2)
			dest[i++] = prefix2;
		while (out && *out)
			dest[i++] = *out++;
		dest[i] = '\0';
		return (dest);
	}
	if (out && *out == '0' && ft_strlen(out) > 1)
	{
		*out = prefix1;
		return (out);
	}
	while ((!prefix2 && out && out[i] == ' ' && out[i + 1] == ' ')
			|| (prefix2 && out && out[i] == ' '
				&& out[i + 1] == ' ' && out[i + 2] == ' '))
		i++;
	out[i++] = prefix1;
	out[i] = prefix2 ? prefix2 : out[i];
	return (out);
}

char	*ft_add_str(char *str, int max)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = ft_memalloc(sizeof(char) * (max + 1))))
		return (NULL);
	while (i < max && max - i > ft_strlen(str))
		dest[i++] = ' ';
	while (*str)
		dest[i++] = *(str++);
	dest[i] = '\0';
	return (dest);
}

int		ft_find_max(t_cs *cs, int min, int prefix)
{
	int	max;
	int	precision;
	int	width;

	precision = cs->precision + prefix;
	width = cs->width;
	max = 0;
	if (precision >= width && precision >= min)
		max = precision;
	if (precision >= width && precision <= min)
		max = min;
	if (precision <= width && precision >= min)
		max = width;
	if (precision < width && precision < min && width >= min)
		max = width;
	if (precision < width && precision < min && width <= min)
		max = min;
	return (max);
}

int		ft_find_min(t_cs *cs, int len, int prefix)
{
	int	precision;

	len += prefix;
	precision = cs->precision + prefix;
	return (precision > len ? precision : len);
}
