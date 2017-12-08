/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:43:18 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/07 22:44:15 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_type(char **dest, const char *str, va_list head, va_list *args)
{
	return (0);
}

int		set_index(char **dest, const char *str, va_list head, va_list *args)
{
	return (0);
}

int		set_flags(char **dest, const char *str, va_list head, va_list *args)
{
	return (0);
}

int		set_width(char **dest, const char *str, va_list head, va_list *args)
{
	return (0);
}

int		set_sep(char **dest, const char *str, va_list head, va_list *args)
{
	return (0);
}

int		set_prec(char **dest, const char *str, va_list head, va_list *args)
{
	return (0);
}

int		set_mod(char **dest, const char *str, va_list head, va_list *args)
{
	return (0);
}

int		is_valide(const char *str)
{
	return (0);
}

int		ft_jump(int i, const char *str, va_list head, va_list *args)
{
	char	*dest;

	set[0] = set_type;
	set[1] = set_index;
	set[2] = set_flags;
	set[3] = set_width;
	set[4] = set_sep;
	set[5] = set_prec;
	set[6] = set_mod;
	dest = NULL;
	while (i > 0)
		str++;
	if (!is_valide(str))
		return (-1);
	i = 0;
	while (i < 6)
		if (!set[i++](&dest, str, head, args))
			return (-1);
	if (dest)
		ft_putstr(dest);
	return (sizeof(dest));
}

int		ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	va_list	head;
	va_list	args;

	i = 0;
	va_start(head, str);
	va_copy(args, head);
	while (str && str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar('%');
			i += 2;
		}
		if (str[i] == '%' && (n = (ft_jump(i, str, head, &args) == -1)))
				return (-1);
		i += n;
		str = va_arg(args, char *);
	}
	va_end(args);
	va_end(head);
	return (i);
}

int		main(int argc, char **argv)
{
	ft_printf("Hello %s%n", "World");
//	printf("Hello %d %d %s". 10, "Actu", 30);
	return (0);
}
