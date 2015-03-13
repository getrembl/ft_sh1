/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 17:29:04 by getrembl          #+#    #+#             */
/*   Updated: 2014/12/03 21:50:52 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	const char	*s1_bkp;

	s1_bkp = s1;
	if (!*s2)
		return ((char *)s1_bkp);
	while (*s1_bkp)
	{
		if (ft_memcmp (s1_bkp, s2, ft_strlen(s2)) == 0)
			return ((char *)s1_bkp);
		s1_bkp++;
	}
	return (NULL);
}
