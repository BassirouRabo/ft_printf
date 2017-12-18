/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:06:54 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/18 01:14:02 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set2.h"

char	*ft_set_x(va_list *args, t_cs *cs)
{
	int		i;
	char	*dest;
	char	*out;
	char	min;
	char	hex[] = {'0', '1', '2', '3', '4', '5', '6',
		'7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	i = -1;
	if (!(out = ft_to_uintmax_t(args, cs)))
		return (NULL);
	if (!(dest = ft_to_base((uint64_t)ft_atoi(out), 16, hex)))
		return (NULL);
	min = ft_find_min(cs, ft_strlen(dest), cs->flag1 ? 2 : 0);
	if (!(dest = ft_add_str(dest, ft_find_max(cs, min, cs->flag1 ? 2 : 0))))
		return (NULL);
	if ((cs->precision || cs->flag2)
			&& !(dest = ft_add_zero(dest, min, cs->flag1 ? 2 : 0)))
		return (NULL);
	if (cs->flag1 && !(dest = ft_add_prefix(dest, '0', 'x')))
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
	char	*out;
	char	oct[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
	char	min;

	if (!(out = ft_to_uintmax_t(args, cs)))
		return (NULL);
	if (!(dest = ft_to_base((uint64_t)ft_atoi(out), 8, oct)))
		return (NULL);
	min = cs->flag1 ? ft_strlen(dest) + 1 : ft_strlen(dest);
	min = cs->precision ? cs->precision : min;
	if (!(dest = ft_add_str(dest, ft_find_max(cs, min, 0))))
		return (NULL);
	if ((cs->precision || cs->flag2) &&
			!(dest = ft_add_zero(dest, min, cs->flag1 ? 1 : 0)))
		return (NULL);
	if (cs->flag1 && !(dest = ft_add_prefix(dest, '0', 0)))
		return (NULL);
	if (cs->flag3 && !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}

char	*ft_set_p(va_list *args, t_cs *cs)
{
	uint64_t	out;
	char		*dest;
	int			max;
	char		hex[] = {'0', '1', '2', '3', '4',
		'5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	out = (uint64_t)va_arg(*args, uint64_t);
	if (!(dest = ft_to_base(out, 16, hex)))
		return (NULL);
	max = cs->width > ft_strlen(dest) ? cs->width : ft_strlen(dest);
	if (!(dest = ft_add_str(dest, max)))
		return (NULL);
	if (!(dest = ft_add_prefix(dest, '0', 'x')))
		return (NULL);
	if (cs->flag3 && !(dest = ft_to_left(dest)))
		return (NULL);
	return (dest);
}
