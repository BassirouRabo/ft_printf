/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:43:18 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/08 23:33:46 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_index(char **dest, const char *str, va_list head, va_list *args,
		t_cs *cs)
{
	if (!ft_isdigit((int)str[1]) && str[2] == '$')
		return (0);
	cs->index = str[1] - '0';
	return (cs->index);
}

int		is_valide(const char *str)
{
	return (1);
}

int		ft_jump(int i, const char *str, va_list head, va_list *args)
{
	t_cs	*cs;
	char	*dest;

	if (!(cs = ft_memalloc(sizeof(t_cs))))
		return (-1);
	set[0] = set_type;
	set[1] = set_index;
	set[2] = set_mod;
	set[3] = set_width;
	set[4] = set_prec;
	set[5] = set_flags;
	dest = NULL;
	while (i-- > 0)
		str++;
	if (!is_valide(str))
		return (-1);
	i = 0;
	while (i < 6)
		if ((set[i++](&dest, str, head, args, cs)) == -1)
			return (-1);
	if (dest)
		ft_putstr (str);
	//  ft_memdel(&cs);
	return (9);
	//return (sizeof(dest));
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
		n = 0;
		if (str[i] != '%')
			ft_putchar(str[i++]);
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar('%');
			i += 2;
		}
		if (str[i] == '%')
		{
			n = ft_jump(i, str, head, &args);
			if (n == -1)
				return (-1);
			i += n;
		}
	// 	str = va_arg(args, char *);
	}
	va_end(args);
	va_end(head);
	return (i);
}

int		main(int argc, char **argv)
{
	ft_printf("Hello world %% alima  %2$04.3ld Jour", "lundi", "mardi");
	return (0);
}
