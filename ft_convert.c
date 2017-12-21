/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:00:14 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/21 15:34:33 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"

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

char	*ft_to_intmax_t(va_list *args, t_cs *cs, int base)
{
	intmax_t	out;

	out = va_arg(*args, intmax_t);
	if (cs->modifier1 == 'h' && cs->modifier2 == 'h')
		out = (char)out;
	else if (cs->modifier2 == 'h')
		out = (short)out;
	else if (cs->modifier1 == 'l' && cs->modifier2 == 'l')
		out = (long long)out;
	else if (!cs->modifier1 && cs->modifier2 == 'l')
		out = (long)out;
	else if (cs->modifier2 == 'j')
		out = (intmax_t)out;
	else if (cs->modifier2 == 'z')
		out = (intmax_t)out;
	else
		out = (int)out;
	return (ft_itoa_base_intmax_t(out, base));
}

char	*ft_to_uintmax_t(va_list *args, t_cs *cs, int base)
{
	uintmax_t	out;

	out = va_arg(*args, uintmax_t);
	if (cs->modifier1 == 'h' && cs->modifier2 == 'h')
		out	= (unsigned char)out;
	else if (!cs->modifier1 &&cs->modifier2 == 'h')
		out	= (unsigned short)out;
	else if (cs->modifier1 == 'l' && cs->modifier2 == 'l')
		out	= (unsigned long long)out;
	else if (!cs->modifier1 && cs->modifier2 == 'l')
		out	= (unsigned long)out;
	else if (cs->modifier2 == 'j')
		out	= (uintmax_t)out;
	else if (cs->modifier2 == 'z')
		out	= (size_t)out;
	else
		out	= (unsigned int)out;
// 	printf("1 [%c] 2 [%c] type[%c] [%zu]\n", cs->modifier1, cs->modifier2, cs->type, out);
	return (ft_itoa_base_uintmax_t(out, base));
}

char	*ft_cut_str(char *out, int min)
{
	int		i;
	char	*dest;

	i = 0;
	if (ft_strlen(out) && ft_strlen(out) <= min)
		return (out);
	if (!(dest = ft_memalloc(min + 1)))
		return (NULL);
	while (min--)
		dest[i++] = out ? *out++ : (char)NULL;
	dest[i] = '\0';
	return (dest);
}

char	*ft_delete_last_zero(t_cs *cs, char *out)
{
	char	*dest;
	int		i;
	int		size;

	i = 0;
	size = cs->width ? ft_strlen(out) + 1 : ft_strlen(out);
	if (!(dest = ft_memalloc(size)))
		return (NULL);
	size = cs->width ? size - 2 : size - 1;
	while (size--)
		dest[i++] = ' ';
	if (cs->width)
		dest[i++] = ' ';
	dest[i] = '\0';
	return (dest);
}







































