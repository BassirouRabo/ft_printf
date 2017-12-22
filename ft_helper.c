/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:53:25 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/21 18:29:30 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_helper.h"

char	*ft_concat(char *dest, char *str, int len)
{
	char	*out;

	len = len ? len : ft_strlen(str);
	if (!(out = ft_memalloc((len + (dest ? ft_strlen(dest) : 0) + 1))))
		exit(0);
	out = ft_strcat(out, dest);
	out = ft_strncat(out, str, len);
	return (out);
}

int		ft_is_valid(char *str)
{
	return (1);
}

char	*ft_add_null(char *out)
{
	char	*dest;

	if (!(dest = ft_memalloc(7)))
		exit (0);
	dest[0] = '(';
	dest[1] = 'n';
	dest[2] = 'u';
	dest[3] = 'l';
	dest[4] = 'l';
	dest[5] = ')';
	dest[6] = '\0';
	return (dest);
}
