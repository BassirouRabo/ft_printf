/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:12:43 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/22 21:37:30 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set1.h"

char	*ft_set_s(va_list *args, t_cs *cs)
{
	int		max;
	int		min;
	char	*out;
	char	*dest;

	out = ft_to_wchar_t_s(args, cs);
	dest = !ft_strlen(out) && !cs->width && !cs->precision
		? ft_add_null(out) : out;
	min = ft_strlen(dest);
	min = cs->precision && cs->precision < min ? cs->precision : min;
	max = (cs->width && cs->width > min) ? cs->width : min;
	dest = ft_cut_str(dest, min);
	dest = ft_add_str(dest, max, cs);
	if (cs->flag3)
		dest = ft_to_left(dest);
	return (dest);
}

char	*ft_set_c(va_list *args, t_cs *cs)
{
	char	*dest;
	char	*out;
	int		max;

	out = ft_to_wchar_t_c(args, cs);
	if (ft_strlen(out))
		max = cs->width > 1 ? cs->width : 1;
	else
		max = cs->width + 1 > 2 ? cs->width + 1 : 2;
	dest = ft_add_np(*out);
	dest = ft_add_str(dest, max, cs);
	if (cs->flag3)
		dest = ft_to_left(dest);
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
	dest = ft_add_str(out, ft_find_max(cs, min, prefix ? 1 : 0), cs);
	if (!cs->precision && cs->digit && !ft_atoi(dest) && min--)
		dest = ft_delete_last_zero(cs, dest);
	if (cs->precision > ft_strlen(out))
		dest = ft_add_zero(dest,
				(cs->precision + (prefix ? 1 : 0)), (prefix ? 1 : 0));
	if (!cs->precision && !cs->flag3 && cs->flag2)
		dest = ft_add_zero(dest, ft_strlen(dest), prefix ? 1 : 0);
	if (prefix)
		dest = ft_add_prefix(dest, prefix, 0);
	if (cs->flag3)
		dest = ft_to_left(dest);
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
	dest = ft_add_str(out, ft_find_max(cs, min, prefix ? 1 : 0), cs);
	if (cs->precision > ft_strlen(out) + (prefix ? 1 : 0))
		dest = ft_add_zero(dest,
				(cs->precision + (prefix ? 1 : 0)), (prefix ? 1 : 0));
	if (!cs->precision && !cs->flag3 && cs->flag2)
		dest = ft_add_zero(dest, ft_strlen(dest), prefix ? 1 : 0);
	if (prefix)
		dest = ft_add_prefix(dest, prefix, 0);
	if (cs->flag3)
		dest = ft_to_left(dest);
	free(out);
	return (dest);
}
