/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:12:43 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/18 01:19:10 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set1.h"

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
	if (cs->flag3 && !(dest = ft_to_left(dest)))
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
	dest[1] = '\0';
	max = cs->width ? cs->width : 1;
	if (!(dest = ft_add_str(dest, max)))
		return (NULL);
	if (cs->flag3 && !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}

char	*ft_set_d(va_list *args, t_cs *cs)
{
	char	*out;
	int		min;
	char	*dest;
	char	prefix;

	prefix = 0;
	if (!(out = ft_to_intmax_t(args, cs)))
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
	if ((cs->precision || cs->flag2)
			&& !(dest = ft_add_zero(dest, min, prefix ? 1 : 0)))
		return (NULL);
	if (prefix && !(dest = ft_add_prefix(dest, prefix, 0)))
		return (NULL);
	if (cs->flag3 && !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}

char	*ft_set_u(va_list *args, t_cs *cs)
{
	char	*out;
	int		min;
	char	*dest;
	char	prefix;

	prefix = 0;
	if (!(out = ft_to_uintmax_t(args, cs)))
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
	if ((cs->precision || cs->flag2) &&
			!(dest = ft_add_zero(dest, min, prefix ? 1 : 0)))
		return (NULL);
	if (prefix && !(dest = ft_add_prefix(dest, prefix, 0)))
		return (NULL);
	if (cs->flag3 && !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}
