/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:43:18 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/16 22:41:53 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_valid(char *str)
{
	return (1);
}

char	*ft_format(char *str, va_list *args)
{
	t_cs	*cs;
	int		i;

	i = 0;
	if (!ft_is_valid(str) || !(cs = ft_memalloc(sizeof(t_cs))))
		return (NULL);
	while (i < 5)
		if (((*get[i++].f)(str, cs)) == -1)
			return (NULL);
	i = 0;
	while (i < 14)
	{
		if (cs->type && cs->type == set[i].type)
			return (*set[i].f)(args, cs);
		i++;
	}
	return (NULL);
}

char	*ft_concat(char *dest, char *str, int len)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (!len)
		len = ft_strlen(str);
	if (!dest)
	{
		if (!(dest = calloc(sizeof(char), (len + 1))))
			return (NULL);
	}
	else
	{
		if (!(dest = realloc(dest, sizeof(char) *(ft_strlen(dest) + len + 1))))
			return (NULL);
	}
	while (dest && dest[i])
		i++;
	while (str && *str && len-- > 0)
		dest[i++] = *str++;
	dest[i] = '\0';
	return (dest);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	char	*dest;

	dest = NULL;
	va_start(args, str);
	while (str && *str)
	{
		if (*str == '%' && *(str + 1) && '%' == *(str + 1)
				&& str++ && !(dest = ft_concat(dest, (char *)str++, 1)))
			return (-1);
		if (*str == '%' && *(str + 1) != '%')
		{
			if (!(dest = ft_concat(dest, ft_format((char *)str, &args), 0)))
				return (-1);
			while (!TYPE(*str))
				 str++;
			str++;
		}
		if (*str != '%' && !(dest = ft_concat(dest, (char *)str++, 1)))
			return (-1);
	}
	ft_putstr(dest);
	va_end(args);
	return (sizeof(dest));
}

int		main(int argc, char **argv)
{
	 printf("[%+12.7d]\n", -123);
	 ft_printf("[%+12.7d]\n", -123);
	//ft_printf("[%d]\n", 350);
	// ft_printf("Hello %% %lld world %s %ls How ", -3450, "bibi", "matano");
//	 ft_printf("Hello %s %S %c %C world", "bibi", "bibi", 'k', 'k');
//	ft_printf("%19.2S\n", "salut");
//	ft_printf("Hello world %% alima  %2$04.3ld Jour", "lundi", "mardi");
//	ft_printf("Hello %ls how", "123");
	return (0);
}
