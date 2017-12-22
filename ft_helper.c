/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:53:25 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/21 23:09:39 by brabo-hi         ###   ########.fr       */
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

int		ft_display(char *dest)
{
	int	i;
	int	len;

	len = ft_strlen(dest);
	i = 0;
	while (dest[i])
	{
		if (dest[i] == '^' && dest[i + 1] && dest[i + 1] == '@')
			len--;
		i++;
	}
	ft_putstr(dest);
	return (len);
}
