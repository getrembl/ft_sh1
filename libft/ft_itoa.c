/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:02:47 by getrembl          #+#    #+#             */
/*   Updated: 2014/11/27 16:52:40 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int n)
{
	char	*itoa;
	int		i;

	i = ft_nbdigit(n);
	if (!(itoa = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	itoa[i] = '\0';
	i--;
	if (n == 0)
		itoa[0] = '0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0 && n > -2147483648)
	{
		n = -n;
		itoa[0] = '-';
	}
	while (n <= 2147483647 && n > 0 && i >= 0)
	{
		itoa[i--] = ((n % 10) + '0');
		n /= 10;
	}
	return (itoa);
}
