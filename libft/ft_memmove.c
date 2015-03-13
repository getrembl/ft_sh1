/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 12:25:32 by getrembl          #+#    #+#             */
/*   Updated: 2014/11/24 10:50:18 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_bkp;
	const char	*src_bkp;

	dst_bkp = (char *)dst;
	src_bkp = (char *)src;
	if (dst && src)
	{
		if (dst_bkp < src_bkp)
		{
			while (len--)
				*dst_bkp++ = *src_bkp++;
			return (dst);
		}
		else
		{
			dst_bkp += len - 1;
			src_bkp += len - 1;
			while (len--)
				*dst_bkp-- = *src_bkp--;
			return (dst);
		}
	}
	return (NULL);
}
