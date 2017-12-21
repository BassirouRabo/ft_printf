/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:04:56 by exam              #+#    #+#             */
/*   Updated: 2017/12/20 18:45:20 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		i;
	int		nbr;
	char	hex[] = {'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	i = 0;
	nbr = value;
	while (nbr)
	{
		nbr = nbr / base;
		i++;
	}
	if (value < 0 && base == 10)
		++i;
	if (!(str = malloc(i + 1)))
		return (NULL);
	nbr = value;
	nbr = nbr < 0 ? - nbr : nbr;
	str[i--] = '\0';
	while (nbr)
	{
		str[i--] = hex[nbr % base];
		nbr = nbr / base;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_base_uintmax_t(uintmax_t value, int base)
{
	char		*str;
	int			i;
	uintmax_t	nbr;
	char		hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	i = value ? 0 : 1;
	nbr = value;
	while (nbr)
	{
		nbr = nbr / base;
		i++;
	}
	if (!(str = malloc(i + 1)))
		return (NULL);
	nbr = value;
	str[i--] = '\0';
	while (nbr)
	{
		str[i--] = hex[nbr % base];
		nbr = nbr / base;
	}
	str[0] = value ? str[0] : '0'; 
	return (str);
}

char	*ft_itoa_base_intmax_t(intmax_t value, int base)
{
	char		*str;
	int			i;
	uintmax_t	nbr;
	int			signe;
	char		hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	i = value ? 0 : 1;
	signe = value < 0 ? 1 : 0;
	nbr= value < 0 ? -value : value;
	while (nbr)
	{
		nbr = nbr / base;
		i++;
	}
	if (value < 0)
		++i;
	if (!(str = malloc(i + 1)))
		return (NULL);
	nbr= value < 0 ? -value : value;
	str[i--] = '\0';
	while (nbr)
	{
		str[i--] = hex[nbr % base];
		nbr = nbr / base;
	}
	if (value < 0)
		str[0] = '-';
	str[0] = value ? str[0] : '0'; 
	return (str);
}
