/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:43:25 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/08 23:32:53 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

# include "ft_struct.h"
# include "ft_set.h"

int		ft_printf(const char * restrict format, ...);
int		ft_jump(int i, const char *str, va_list head, va_list *args);
int		is_valide(const char *str);

int		set_index(char **dest, const char *str, va_list head, va_list *args, t_cs *cs);

#endif
