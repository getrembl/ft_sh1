/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:08:18 by getrembl          #+#    #+#             */
/*   Updated: 2014/12/01 16:55:52 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		index;

	index = 0;
	if (!dst || !src)
		return (NULL);
	while (n > 0 && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
		n--;
	}
	while (n--)
		dst[index++] = '\0';
	return (dst);
}
