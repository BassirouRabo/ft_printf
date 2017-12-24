/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:43:18 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/23 20:30:14 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format(char *str, va_list *args)
{
	char	*dest;
	t_cs	*cs;
	int		i;

	i = 0;
	if (!(cs = ft_memalloc(sizeof(t_cs))))
		exit(0);
	while (i < 5)
		if (((*t_gets[i++].f)(str, cs)) == -1)
			return (NULL);
	i = 0;
	while (i < 15)
	{
		if (cs->type && cs->type == t_sets[i].type)
		{
			dest = (*t_sets[i].f)(args, cs);
			free(cs);
			return (dest);
		}
		i++;
	}
	return (NULL);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	char	*dest;
	char	*out;

	dest = NULL;
	va_start(args, str);
	if (!ft_is_valid((char *)str))
		return (0);
	while (str && *str)
	{
		if (*str == '%' && str++)
		{
			if (!(dest = ft_concat(dest, out = ft_format((char *)str, &args), 0)))
				return (-1);
			free(out);
			while (!TYPE(*str))
				str++;
			str++;
		}
		if (str && *str != '%' && *str != '\0')
			if ((!(dest = ft_concat(dest, (char *)str++, 1))))
				return (-1);
	}
	if (!dest)
		return (0);
	va_end(args);
	return (ft_display(dest));
}

int		main1(void)
{
 	printf("%d\n", printf("%k"));
 	printf("%d\n", ft_printf("%"));
	return (0);
}
