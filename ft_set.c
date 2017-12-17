/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 01:08:48 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/16 22:41:43 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

char	*ft_display(char *str, t_cs *cs, int width, int len)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = ft_memalloc(width + 1)))
		return (NULL);
	while (i < width)
	{
		if (!cs->flag3)
		{
			if (i < width - len)
				dest[i] = ' ';
			else
				dest[i] = *(str++);
		}
		else
		{
			if (i < len)
				dest[i] = *(str++);
			else
				dest[i] = ' ';
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_set_s(va_list *args, t_cs *cs)
{
	int		width;
	int		len;
	char	*out;

	if (cs->modifier2 == 'l' || cs->type == 'S')
		return (ft_set_S(args, cs));
	out = (char *)va_arg(*args, char *);
	len = ft_strlen(out);
	width = (cs->width && cs->width > len) ? cs->width : len;
	len = cs->precision && cs->precision < len ? cs->precision : len;
	return (ft_display(out, cs, width, len));
}

char	*ft_set_S(va_list *args, t_cs *cs)
{
	int		width;
	int		len;
	char	*out;
	char	*str;
	int		i;

	out = (char	*)va_arg(*args, char *);
	i = 0;
	len = ft_strlen(out);
	if (!(str = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = out[i] >= 97 && out[i] <= 122 ? out[i] - 32 : out[i];
		i++;
	}
	str[i] = '\0';
	len = ft_strlen(str);
	width = (cs->width && cs->width > len) ? cs->width : len;
	len = cs->precision && cs->precision < len ? cs->precision : len;
	return (ft_display(str, cs, width, len));
}

char	*ft_set_c(va_list *args, t_cs *cs)
{
	int		width;
	char	out;

	if (cs->modifier2 == 'l' || cs->type == 'C')
		return (ft_set_C(args, cs));
	out = (unsigned char)va_arg(*args, int);
	width = cs->width ? cs->width : 1;
	return (ft_display(&out, cs, width, 1));
}

char	*ft_set_C(va_list *args, t_cs *cs)
{
	int		width;
	char	out;

	out = (char)va_arg(*args, int);
	out = out >= 97 && out <= 122 ? out - 32 : out;
	width = cs->width ? cs->width : 1;
	return (ft_display(&out, cs, width, 1));
}

char	*ft_set_p(va_list *args, t_cs *cs)
{

	return (NULL);
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

char	*ft_to_intmax_t(va_list *args, t_cs *cs)
{
	char	*out;

	out = NULL;
	if (cs->modifier2 == 'h')
		out = ft_itoa((intmax_t)va_arg(*args, int));
	if (cs->modifier1 == 'l' && cs->modifier2 == 'l')
		out = ft_itoa((intmax_t)va_arg(*args, long long));
	if (!cs->modifier1 && cs->modifier2 == 'l')
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
	if (!cs->modifier1 && cs->modifier2 == 'l')
		out = ft_itoa((uintmax_t)va_arg(*args, unsigned long));
	if (cs->modifier2 == 'j')
		out = ft_itoa((uintmax_t)va_arg(*args, uintmax_t));
	if (cs->modifier2 == 'z')
		out = ft_itoa((uintmax_t)va_arg(*args, size_t));
	if (!cs->modifier1 && !cs->modifier2)
		out = ft_itoa((uintmax_t)va_arg(*args, int));
	return (out);
}

char	*ft_add_zero(char *dest, int min, char prefix)
{
	int	i;

	i = 0;
	min = prefix ? min - 1 : min;
	if (*dest != ' ')
		return (dest);
	while (dest[i] == ' ' && (i < ft_strlen(dest) - min))
		i++;
	while (dest[i] == ' ')
		dest[i++] = '0';
	return (dest);
}

char	*ft_add_prefix(char *out, char prefix)
{
	int		i;
	char	*dest;

	i = 0;
	if (*out != '0' && *out != ' ')
	{
		if (!(dest = ft_memalloc(ft_strlen(out) + 2)))
			return (NULL);
		dest[i++] = prefix;
		while (out && *out)
			dest[i++] = *out++;
		dest[i] = '\0';
		return (dest);
	}
	if (out && *out == '0' && ft_strlen(out) > 1)
	{
		*out = prefix;
		return (out);
	}
	while (out && out[i] == ' ' && out[i + 1] == ' ')
		i++;
	out[i] = prefix;
	return (out);
}

int		ft_find_max(t_cs *cs, int min, char  prefix)
{
	int	max;
	int	precision;
	int	width;
	int	size_prefix;

	size_prefix = prefix ? 1 : 0;
	precision = cs->precision + size_prefix;
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

int		ft_find_min(t_cs *cs, int len, char prefix)
{
	int	precision;
	int size_prefix;

	size_prefix = prefix ? 1 : 0;
	len += size_prefix;
	precision = cs->precision + size_prefix;
	return (precision > len ? precision : len);
}

char	*ft_set_d(va_list *args, t_cs *cs)
{
	char	*out;;
	int		min;
	int		width;
	char	*dest;
	char	prefix;

	prefix = 0;
	if(!(out = ft_to_intmax_t(args, cs)))
		return (NULL);
	if (*out == '-' && out++)
		prefix = '-';
	if (*out != '-' && cs->flag5)
		prefix = ' ';
	if (*out != '-' && cs->flag4)
		prefix = prefix ? '-' : '+';
	min = ft_find_min(cs, ft_strlen(out), prefix);
	if (!(dest = ft_add_str(out, ft_find_max(cs, min, prefix))))
		return (NULL);
	if ((cs->precision || cs->flag2) && !(dest = ft_add_zero(dest, min, prefix)))
			return (NULL);
	if(prefix && !(dest = ft_add_prefix(dest, prefix)))
		return (NULL);
	return (dest);
}

char	*ft_set_o(va_list *args, t_cs *cs)
{
	char	*out;
	char	oct[] = {'0', '1', '2', '3', '4', '5', '6', '7'};

	if(!(out = ft_to_uintmax_t(args, cs)))
		return (NULL);
	ft_to_base(7562, 8, oct);

	return (NULL);
}

char	*ft_set_u(va_list *args, t_cs *cs)
{
	char	*out;

	if(!(out = ft_to_uintmax_t(args, cs)))
		return (NULL);

	return (NULL);
}

char	*ft_to_base(int number, int base, char bases[])
{
	int		i;
	char	*dest;
	int		nbr;

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

char	*ft_set_x(va_list *args, t_cs *cs)
{
	char	*out;
	char	hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	if(!(out = ft_to_uintmax_t(args, cs)))
		return (NULL);
	ft_to_base(7562, 16, hex);
	return (NULL);
}

char	*ft_set_X(va_list *args, t_cs *cs)
{
	char	*out;
	char	hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	if(!(out = ft_to_uintmax_t(args, cs)))
		return (NULL);

	return (NULL);
}

