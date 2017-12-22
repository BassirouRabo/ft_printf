/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 23:13:01 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/21 23:13:21 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ADD_H
# define FT_ADD_H

# include "ft_struct.h"

char	*ft_add_zero(char *dest, int min, int prefix);
char	*ft_add_prefix(char *out, char prefix1, char prefix2);
char	*ft_add_str(char *str, int max, t_cs *cs);
char	*ft_add_null(char *out);
char	*ft_add_np(char c);

#endif
