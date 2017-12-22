/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:12:43 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/21 18:44:53 by brabo-hi         ###   ########.fr       */
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
   	dest = !ft_strlen((char *)out) && !cs->width && !cs->precision ? ft_add_null((char *)out) : (char *)out;
	min = ft_strlen((char *)dest);
	min = cs->precision && cs->precision < min ? cs->precision : min;
	max = (cs->width && cs->width > min) ? cs->width : min;
	if (!(dest = ft_cut_str(dest, min)))
		return (NULL);
	if (!(dest = ft_add_str(dest, max, cs)))
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
	if (!(dest = ft_memalloc(2)))
		return (NULL);
	dest[0] = out;
	dest[1] = '\0';
	max = cs->width ? cs->width : ft_strlen((char *)&out);
	if (!ft_strlen((char *)&out))
		max = max ? max - 1 : 0;
	if (!(dest = ft_add_str(dest, max, cs)))
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
	if (!(out = ft_to_intmax_t(args, cs, 10)))
		return (NULL);
	if (*out == '-')
		prefix = '-';
	if (*out != '-' && cs->flag5)
		prefix = ' ';
	if (*out != '-' && cs->flag4)
		prefix = '+';
	if (*out == '-')
		out++;

	min = ft_find_min(cs, ft_strlen(out), prefix ? 1 : 0);

	if (!(dest = ft_add_str(out, ft_find_max(cs, min, prefix ? 1 : 0), cs)))
		return (NULL);

	if (!cs->precision && cs->digit  && !ft_atoi(dest) && min-- && !(dest = ft_delete_last_zero(cs, dest)))
		return (NULL);

	if (cs->precision > ft_strlen(out) 
			&& !(dest = ft_add_zero(dest, (cs->precision + (prefix ? 1 : 0)), (prefix ? 1 : 0))))
		return (NULL);

	if (!cs->precision && !cs->flag3 && cs->flag2
			&& !(dest = ft_add_zero(dest, ft_strlen(dest), prefix ? 1 : 0)))
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
	if (!(out = ft_to_uintmax_t(args, cs, 10)))
		return (NULL);
	if (*out == '-' && out++)
		prefix = '-';
	if (*out != '-' && cs->flag5)
		prefix = 0;
	if (*out != '-' && cs->flag4)
		prefix = prefix ? '-' : 0;

	min = ft_find_min(cs, ft_strlen(out), prefix ? 1 : 0);

	if (!(dest = ft_add_str(out, ft_find_max(cs, min, prefix ? 1 : 0), cs)))
		return (NULL);

	if (cs->precision > ft_strlen(out) + (prefix ? 1 : 0)
			&& !(dest = ft_add_zero(dest, (cs->precision + (prefix ? 1 : 0)), (prefix ? 1 : 0))))
		return (NULL);

	if (!cs->precision && !cs->flag3 && cs->flag2
			&& !(dest = ft_add_zero(dest, ft_strlen(dest), prefix ? 1 : 0)))
		return (NULL);

	if (prefix && !(dest = ft_add_prefix(dest, prefix, 0)))
		return (NULL);

	if (cs->flag3 && !(dest = ft_to_left(dest)))
		return (NULL);

	return (dest);
}
