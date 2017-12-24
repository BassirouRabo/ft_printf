/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:53:25 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/23 20:23:41 by brabo-hi         ###   ########.fr       */
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
 	free(dest);
	return (out);
}

int		ft_is_valid(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] == '%' && ++i)
		{
			while (str && str[i] && !TYPE(str[i]))
			{
				if (!MOD(str[i]) && !FLAGS(str[i]) && !ft_isdigit(str[i]))
					return (0);
				i++;
			}
			if (!TYPE(str[i]))
				return (0);
		}
	}
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
	free(dest);
	return (len);
}
