/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:53:39 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/21 18:37:02 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELPER_H
# define FT_HELPER_H

# include "ft_struct.h"

int		ft_is_valid(char *str);
char	*ft_concat(char *dest, char *str, int len);
char	*ft_add_null(char *out);

#endif
