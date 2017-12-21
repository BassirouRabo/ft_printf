/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:00:29 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/21 02:23:19 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

# include "ft_struct.h"

char	*ft_to_left(char *str);
char	*ft_to_intmax_t(va_list *args, t_cs *cs, int base);
char	*ft_to_uintmax_t(va_list *args, t_cs *cs, int base);
char	*ft_cut_str(char *out, int min);
char	*ft_delete_last_zero(t_cs *cs, char *out);

#endif
