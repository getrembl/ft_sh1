* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:59:32 by getrembl          #+#    #+#             */
/*   Updated: 2015/04/23 20:42:44 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	int		index;

	index = 0;
	if (src && dst)
	{
		while ((dst[index] = src[index]) != '\0')
			index++;
		dst[index] = '\0';
		return (dst);
	}
	return (NULL);
}
