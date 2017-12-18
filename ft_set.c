/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 01:08:48 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/17 23:43:29 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

char	*ft_cut_str(char *out, int min)
{
	int		i;
	char	*dest;

	i = 0;
	if (ft_strlen(out) <= min)
		return (out);
	if (!(dest = ft_memalloc(sizeof(char) *(min + 1))))
		return (NULL);
	while (min--)
		dest[i++] = *out++;
	dest[i] = '\0';
	free(out);
	out = NULL;
	return (dest);
}

char	*ft_set_s(va_list *args, t_cs *cs)
{
	int		i;
	int		max;
	int		min;
	wchar_t	*out;
	char	*dest;

	i = 0;
	if (cs->modifier2 == 'l' || cs->type == 'S')
		out = (wchar_t *)va_arg(*args, wchar_t *);
	else
		out = (wchar_t *)va_arg(*args, char *);
	min = ft_strlen((char *)out);
	min = cs->precision && cs->precision < min ? cs->precision : min;
	max = min;
	max = (cs->width && cs->width > min) ? cs->width : max;
	if (!(dest = ft_cut_str((char *)out, min)))
		return (NULL);
 	if (!(dest = ft_add_str(dest, max)))
		return (NULL);
	if (cs->flag3 &&  !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}

char	*ft_set_c(va_list *args, t_cs *cs)
{
	char	*dest;
	int		max;
	wchar_t	out;

	if (cs->modifier2 == 'l' || cs->type == 'C')
		out = (wchar_t)va_arg(*args, wchar_t);
	else
		out = (unsigned char)va_arg(*args, int);
	if (!(dest = ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	dest[0] = out;
	dest[1]= '\0';
	max = cs->width ? cs->width : 1;
 	if (!(dest = ft_add_str(dest, max)))
		return (NULL);
	if (cs->flag3 &&  !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}

char	*ft_set_p(va_list *args, t_cs *cs)
{
	uint64_t	out;
	char		*dest;
	int			max;
	char	hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	out = (uint64_t)va_arg(*args, uint64_t);
	if (!(dest = ft_to_base(out, 16, hex)))
		return (NULL);
	max = cs->width > ft_strlen(dest) ? cs->width : ft_strlen(dest);
	if (!(dest = ft_add_str(dest, max)))
		return (NULL);
	if (!(dest = ft_add_prefix(dest, '0', 'x')))
		return (NULL);
	if (cs->flag3 &&  !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
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
	if ((!cs->modifier1 && cs->modifier2 == 'l') || cs->type == 'O' || cs->type == 'U')
		out = ft_itoa((uintmax_t)va_arg(*args, unsigned long));
	if (cs->modifier2 == 'j')
		out = ft_itoa((uintmax_t)va_arg(*args, uintmax_t));
	if (cs->modifier2 == 'z')
		out = ft_itoa((uintmax_t)va_arg(*args, size_t));
	if (!cs->modifier1 && !cs->modifier2)
		out = ft_itoa((uintmax_t)va_arg(*args, int));
	return (out);
}

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
	while ((!prefix2 && out && out[i] == ' ' && out[i + 1] == ' ') || (prefix2 && out && out[i] == ' ' && out[i + 1] == ' ' && out[i + 2] == ' '))
		i++;
	out[i++] = prefix1;
	out[i] = prefix2 ? prefix2 : out[i];
	return (out);
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

int		ft_find_min(t_cs *cs, int len, int  prefix)
{
	int	precision;

	len += prefix;
	precision = cs->precision + prefix;
	return (precision > len ? precision : len);
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
	min = ft_find_min(cs, ft_strlen(out), prefix ? 1 : 0);
	if (!(dest = ft_add_str(out, ft_find_max(cs, min, prefix ? 1 : 0))))
		return (NULL);
	if ((cs->precision || cs->flag2) && !(dest = ft_add_zero(dest, min, prefix ? 1 : 0)))
			return (NULL);
	if (prefix && !(dest = ft_add_prefix(dest, prefix, 0)))
		return (NULL);
	if (cs->flag3 &&  !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}

char	*ft_set_x(va_list *args, t_cs *cs)
{
	int		i;
	char	*dest;
	char	*out;
	char	min;
	char	hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	i = -1;
	if(!(out = ft_to_uintmax_t(args, cs)))
		return (NULL);
	if (!(dest = ft_to_base((uint64_t)ft_atoi(out), 16, hex)))
		return (NULL);
	min = ft_find_min(cs, ft_strlen(dest), cs->flag1 ? 2 : 0);
	if (!(dest = ft_add_str(dest, ft_find_max(cs, min, cs->flag1 ? 2 : 0))))
		return (NULL);
	if ((cs->precision || cs->flag2) && !(dest = ft_add_zero(dest, min, cs->flag1 ? 2 : 0)))
			return (NULL);
	if (cs->flag1 && !(dest = ft_add_prefix(dest, '0', 'x')))
		return (NULL);
	if (cs->flag3 &&  !(dest = ft_to_left(dest)))
		return (NULL);
	if (cs->type == 'X')
	while (++i < ft_strlen(dest))
		dest[i] = (char)ft_toupper(dest[i]);
	return (dest);
}

char	*ft_set_o(va_list *args, t_cs *cs)
{
	char	*dest;
	char	*out;
	char	oct[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
	char	min;
	if(!(out = ft_to_uintmax_t(args, cs)))
		return (NULL);
	if (!(dest = ft_to_base((uint64_t)ft_atoi(out), 8, oct)))
		return (NULL);
	min = cs->flag1 ? ft_strlen(dest) + 1 : ft_strlen(dest);
	min = cs->precision ? cs->precision : min; 
	if (!(dest = ft_add_str(dest, ft_find_max(cs, min, 0))))
		return (NULL);
	if ((cs->precision || cs->flag2) && !(dest = ft_add_zero(dest, min, cs->flag1 ? 1 : 0)))
			return (NULL);
	if (cs->flag1 && !(dest = ft_add_prefix(dest, '0', 0)))
		return (NULL);
	if (cs->flag3 &&  !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}

char	*ft_set_u(va_list *args, t_cs *cs)
{
	char	*out;
	int		min;
	int		width;
	char	*dest;
	char	prefix;

	prefix = 0;
	if(!(out = ft_to_uintmax_t(args, cs)))
		return (NULL);
	if (*out == '-' && out++)
		prefix = '-';
	if (*out != '-' && cs->flag5)
		prefix = ' ';
	if (*out != '-' && cs->flag4)
		prefix = prefix ? '-' : '+';
	min = ft_find_min(cs, ft_strlen(out), prefix ? 1 : 0);
	if (!(dest = ft_add_str(out, ft_find_max(cs, min, prefix ? 1 : 0))))
		return (NULL);
	if ((cs->precision || cs->flag2) && !(dest = ft_add_zero(dest, min, prefix ? 1 : 0)))
			return (NULL);
	if (prefix && !(dest = ft_add_prefix(dest, prefix, 0)))
		return (NULL);
	if (cs->flag3 &&  !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}

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
