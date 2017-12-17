/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:43:25 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/16 22:41:50 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_struct.h"
# include "ft_get.h"
# include "ft_set.h"

int		ft_printf(const char * restrict format, ...);
int		ft_is_valid(char *str);
char	*ft_format(char *str, va_list *args);
char	*ft_concat(char *dest, char *str, int len);

typedef struct		s_get
{
	int				(*f)(char *, t_cs *);
}					t_get;

typedef struct		s_set
{
	char			type;
	char			*(*f)(va_list *, t_cs *);
}					t_set;

t_set	set[] =
{
	{ 's', ft_set_s },
	{ 'S', ft_set_s },
	{ 'p', ft_set_p },
	{ 'd', ft_set_d },
	{ 'D', ft_set_d },
	{ 'i', ft_set_d },
	{ 'o', ft_set_o },
	{ 'O', ft_set_o },
	{ 'u', ft_set_u },
	{ 'U', ft_set_u },
	{ 'x', ft_set_x },
	{ 'X', ft_set_X },
	{ 'c', ft_set_c },
	{ 'C', ft_set_C }
};

t_get	get[] =
{
	{ ft_get_type },
	{ ft_get_mod },
	{ ft_get_width },
	{ ft_get_prec },
	{ ft_get_flags }
};

#endif
