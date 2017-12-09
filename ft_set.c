/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:43:18 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/08 23:19:49 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

int		set_type(char **dest, const char *str, va_list head, va_list *args,
		t_cs *cs)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (TYPE(str[i]))
		{
			cs->type = str[i];
			return (1);
		}
		i++;
	}
	return (-1);
}

int		set_flags(char **dest, const char *str, va_list head, va_list *args,
		t_cs *cs)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (str && str[i] && !TYPE(str[i]))
	{
		if (FLAGS(str[i]))
			t = 1;
		if (str[i] == '#')
			cs->flag1 = str[i];
		if (str[i] == '0')
			cs->flag2 = str[i];
		if (str[i] == '-')
			cs->flag3 = str[i];
		if (str[i] == '+')
			cs->flag4 = str[i];
		if (str[i] == ' ')
			cs->flag5 = str[i];
		i++;
	}
	return (t ? 1 : 0);
}

int		set_width(char **dest, const char *str, va_list head, va_list *args,
		t_cs *cs)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
	{
		if (!ft_isdigit((int)str[i - 1]))
			return (-1);
		cs->width = str[i - 1] - '0';
	   return (1);	
	}
	return (0);
}

int		set_prec(char **dest, const char *str, va_list head, va_list *args,
		t_cs *cs)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '.')
		i++;
	printf(" * ");
	if (str[i] && str[i] == '.')
	{
		if (!ft_isdigit((int)str[i + 1]))
			cs->precision = 0;
		else
			cs->precision = str[i + 1] - '0';
		return (1);
	}
	return (0);
}

int		set_mod(char **dest, const char *str, va_list head, va_list *args,
		t_cs *cs)
{
	int		i;

	i = 0;
	while (!TYPE(str[i]))
		i++;
	i--;
	if (str[i] == 'j' || str[i] == 'z')
	{
		cs->modifier2 = str[i]; 
		return (1);
	}
	if (str[i] == 'h' || str[i] == 'l')
	{
		if (str[i - 1] == 'h' || str[i - 1] == 'l')
		{
			cs->modifier1 = str[i]; 
			cs->modifier2 = str[i - 1]; 
			return (2);
		}
		cs->modifier2 = str[i];
		return (1);
	}
	return (0);
}
