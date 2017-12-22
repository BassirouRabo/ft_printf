/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:06:54 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/21 16:04:36 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set2.h"

char	*ft_set_x(va_list *args, t_cs *cs)
{
	int		i;
	char	*out;
	char	*dest;
	char	min;
	int		size_prefix;

	i = -1;
	if (!(out = ft_to_uintmax_t(args, cs, 16)))
		return (NULL);
	min = ft_find_min(cs, ft_strlen(out), cs->flag1 ? 2 : 0);
	min = ft_atoi(out) ? min : 1;
	size_prefix = cs->flag1 ? 2 : 0;
	size_prefix = ft_atoi(out) ? size_prefix : 0;

	if (!(dest = ft_add_str(out, ft_find_max(cs, min, size_prefix), cs)))
		return (NULL);

	if (!cs->precision && cs->digit  && !ft_atoi(dest) && min-- && !(dest = ft_delete_last_zero(cs, dest)))
		return (NULL);

	if (cs->precision > ft_strlen(out) + size_prefix
			&& !(dest = ft_add_zero(dest, (cs->precision + size_prefix), size_prefix)))
		return (NULL);

	if (!cs->precision && !cs->flag3 && cs->flag2
			&& !(dest = ft_add_zero(dest, ft_strlen(dest), size_prefix)))
		return (NULL);

	if (size_prefix && !(dest = ft_add_prefix(dest, '0', 'x')))
		return (NULL);

	if (cs->flag3 && !(dest = ft_to_left(dest)))
		return (NULL);
	
	if (cs->type == 'X')
		while (++i < ft_strlen(dest))
			dest[i] = (char)ft_toupper(dest[i]);
	return (dest);
}

char	*ft_set_o(va_list *args, t_cs *cs)
{
	char	*dest;
	char	min;

	if (!(dest = ft_to_uintmax_t(args, cs, 8)))
		return (NULL);
	min = cs->flag1 ? ft_strlen(dest) + 1 : ft_strlen(dest);
	min = cs->precision ? cs->precision : min;
	if (!(dest = ft_add_str(dest, ft_find_max(cs, min, 0), cs)))
		return (NULL);
	if (!cs->precision && cs->digit  && !ft_atoi(dest) && min-- && !(dest = ft_delete_last_zero(cs, dest)))
		return (NULL);
	if ((cs->precision || cs->flag2) &&
			!(dest = ft_add_zero(dest, min, cs->flag1 ? 1 : 0)))
		return (NULL);

	if (!cs->precision && !cs->flag3 && cs->flag2
			&& !(dest = ft_add_zero(dest, ft_strlen(dest), cs->flag1 ? 1 : 0)))
		return (NULL);

	if (cs->flag1 && !(dest = ft_add_prefix(dest, '0', 0)))
		return (NULL);
	if (cs->flag3 && !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}

char	*ft_set_p(va_list *args, t_cs *cs)
{
	char		*dest;
	int			max;

	if (!(dest = ft_to_uintmax_t(args, cs, 16)))
		return (NULL);
	max = cs->width > ft_strlen(dest) ? cs->width : ft_strlen(dest);
	if (!(dest = ft_add_str(dest, max, cs)))
		return (NULL);
	if (!(dest = ft_add_prefix(dest, '0', 'x')))
		return (NULL);
	if (cs->flag3 && !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}

char	*ft_set_z(va_list *args, t_cs *cs)
{
	char	*dest;
	int		max;

	if (!(dest = ft_memalloc(sizeof(char) * 2)))
		exit(0);
	dest[0] = '%';
	dest[1] = '\0';
	max = cs->width ? cs->width : 1;
	if (!(dest = ft_add_str(dest, max, cs)))
		return (NULL);
	if (cs->flag3 && !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}
