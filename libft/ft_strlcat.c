/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:36:33 by getrembl          #+#    #+#             */
/*   Updated: 2014/11/24 21:54:26 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_bkp;
	const char	*src_bkp;
	size_t		size_bkp;
	size_t		dstlen;

	dst_bkp = dst;
	src_bkp = src;
	size_bkp = size;
	while (size_bkp-- != 0 && *dst_bkp != '\0')
		dst_bkp++;
	dstlen = dst_bkp - dst;
	size_bkp = size - dstlen;
	if (size_bkp == 0)
		return (dstlen + ft_strlen(src_bkp));
	while (*src_bkp != '\0')
	{
		if (size_bkp != 1)
		{
			*dst_bkp++ = *src_bkp;
			size_bkp--;
		}
		src_bkp++;
	}
	*dst_bkp = '\0';
	return (dstlen + (src_bkp - src));
}
