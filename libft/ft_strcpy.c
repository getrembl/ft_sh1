/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:59:32 by getrembl          #+#    #+#             */
/*   Updated: 2014/11/27 17:19:05 by getrembl         ###   ########.fr       */
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
