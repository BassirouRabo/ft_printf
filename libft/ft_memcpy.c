/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:43:46 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/22 21:38:05 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *restrict	copy;
	size_t	size;

	copy = dst;
	size = n;
	while (n--)
		*(char *)dst++ = *(char *)src++;
	*(char *)dst = '\0';
	return (copy);
}
