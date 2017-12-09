/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:43:25 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/08 23:25:15 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_H
# define FT_SET_H

# include "ft_struct.h"

int		set_type(char **dest, const char *str, va_list head, va_list *args, t_cs *cs);
int		set_flags(char **dest, const char *str, va_list head, va_list *args, t_cs *cs);
int		set_width(char **dest, const char *str, va_list head, va_list *argsi, t_cs *cs);
int		set_prec(char **dest, const char *str, va_list head, va_list *argsi, t_cs *cs);
int		set_mod(char **dest, const char *str, va_list head, va_list *args, t_cs *cs);

#endif
