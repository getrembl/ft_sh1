/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:47:23 by getrembl          #+#    #+#             */
/*   Updated: 2014/11/27 16:55:28 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	const char	*s_bkp;

	s_bkp = s;
	while (n-- && s)
	{
		if (*s_bkp == (char)c)
			return ((void *)s_bkp);
		s_bkp++;
	}
	return (NULL);
}
