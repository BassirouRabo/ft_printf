/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 01:09:04 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/17 23:54:51 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_H
# define FT_SET_H

# include "ft_struct.h"

char	*ft_set_s(va_list *args, t_cs *cs);
char	*ft_set_p(va_list *args, t_cs *cs);
char	*ft_set_d(va_list *args, t_cs *cs);
char	*ft_set_o(va_list *args, t_cs *cs);
char	*ft_set_u(va_list *args, t_cs *cs);
char	*ft_set_x(va_list *args, t_cs *cs);
char	*ft_set_c(va_list *args, t_cs *cs);

char	*ft_add_str(char *str, int max);
char	*ft_add_zero(char *dest, int min, int prefix);
char	*ft_add_prefix(char *out, char prefix1, char prefix2);
int		ft_find_max(t_cs *cs, int min, int prefix);
int		ft_find_min(t_cs *cs, int len, int prefix);
char	*ft_to_base(uint64_t number, int base, char bases[]);
char	*ft_to_intmax_t(va_list *args, t_cs *cs);
char	*ft_to_uintmax_t(va_list *args, t_cs *cs);
char	*ft_to_left(char *str);

#endif
