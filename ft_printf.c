/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:43:18 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/21 18:41:39 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format(char *str, va_list *args)
{
	t_cs	*cs;
	int		i;

	i = 0;
	if (!ft_is_valid(str) || !(cs = ft_memalloc(sizeof(t_cs))))
		return (NULL);
	if (!(cs = ft_memalloc(sizeof(t_cs))))
		exit(0);
	while (i < 5)
		if (((*t_gets[i++].f)(str, cs)) == -1)
			return (NULL);
	i = 0;
	while (i < 15)
	{
		if (cs->type && cs->type == t_sets[i].type)
			return (*t_sets[i].f)(args, cs);
		i++;
	}
	return (NULL);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	char	*dest;

	dest = NULL;
	va_start(args, str);
	while (str && *str)
	{
		if (*str == '%' && str++)
		{
			if (!(dest = ft_concat(dest, ft_format((char *)str, &args), 0)))
				return (-1);
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
	ft_putstr(dest);
	va_end(args);
	return (ft_strlen(dest));
}

int		maini(void)
{
	char	s[] = {0};
	char	c	= 0%31;
	int	len;

	char	dest[2];
	dest[0] = 0*31;
	dest[1] = '\0';

// 	len = printf("%c", c);
//	printf("\nlen %d\n", len);
//	ft_printf("[%c]\n", 0);
	ft_printf("%s\n", NULL);
	return (0);
}
