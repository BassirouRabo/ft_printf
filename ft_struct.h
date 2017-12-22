/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 23:21:37 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/21 22:50:00 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# define TYPE(t)  (t == 's' || t == 'S' || t == 'p' ||  t == 'D' || t == 'i'\
		|| t == 'o' || t == 'O' || t == 'u' || t == 'U' || t == 'x'\
		|| t == 'X' || t == 'c' || t == 'C' || t == 'd' || t == '%')
# define TYPE_UP(t) (t == 'D' || t == 'O' || t == 'U' || t == 'C' || t == 'S')
# define FLAGS(t) (t == '#' || t == '0' || t == '-' || t == '+' || t == ' ')

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_cs
{
	char			index;
	char			flag1;
	char			flag2;
	char			flag3;
	char			flag4;
	char			flag5;
	int				width;
	int				precision;
	char			modifier1;
	char			modifier2;
	char			type;
	int				digit;
}					t_cs;

#endif
