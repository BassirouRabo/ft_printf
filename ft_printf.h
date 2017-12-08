/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:43:25 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/07 22:42:28 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TYPE(t) = (t == 's' || t == 'S' || t == 'p' ||  t == 'D' || t == 'i'\
		|| t == 'o' || t == 'O' || t == 'u' || t == 'U' || t == 'x'\
		|| t == 'X' || x == 'c' || t == 'C' || t == 'D')

# include <stdarg.h>
# include <stdlib.h>

# include <stdio.h> // To delete

# include "../libft/libft.h"

typedef struct		s_cs
{
	char	index;	// *
	char	*flags;
	char	separator;
	int		width;	// *
	char	precision;	// *
	char	*modifier;
	char	type;
}					t_cs;

int		ft_printf(const char * restrict format, ...);
int		ft_jump(int i, const char *str, va_list head, va_list *args);
int		is_valide(const char *str);

int		(*set[7])(char **, const char *, va_list, va_list *);

int		set_index(char **dest, const char *str, va_list head, va_list *args);
int		set_type(char **dest, const char *str, va_list head, va_list *args);
int		set_flags(char **dest, const char *str, va_list head, va_list *args);
int		set_width(char **dest, const char *str, va_list head, va_list *args);
int		set_sep(char **dest, const char *str, va_list head, va_list *args);
int		set_prec(char **dest, const char *str, va_list head, va_list *args);
int		set_mod(char **dest, const char *str, va_list head, va_list *args);

#endif
