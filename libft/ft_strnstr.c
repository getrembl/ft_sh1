/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:00:33 by getrembl          #+#    #+#             */
/*   Updated: 2015/02/09 15:55:37 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*s1_bkp;

	s1_bkp = s1;
	if (!s2)
		return ((char *)s1_bkp);
	if (s1_bkp)
	{
		while (*s1_bkp && n)
		{
			if (ft_memcmp(s1_bkp, s2, ft_strlen(s2)) == 0
				&& n >= ft_strlen(s2))
				return ((char *)s1_bkp);
			s1_bkp++;
			n--;
		}
	}
	return (NULL);
}
