/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:49:02 by getrembl          #+#    #+#             */
/*   Updated: 2014/11/24 22:06:03 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_bkp;
	const char	*src_bkp;
	size_t		i;

	if (dst || src)
	{
		dst_bkp = dst;
		src_bkp = src;
		i = 0;
		while (n--)
		{
			dst_bkp[i++] = *src_bkp++;
		}
		dst_bkp[i] = '\0';
		return (dst);
	}
	return (NULL);
}
