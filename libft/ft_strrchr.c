/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 20:12:23 by getrembl          #+#    #+#             */
/*   Updated: 2014/11/24 21:52:36 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	const char	*s_bkp;

	s_bkp = s + ft_strlen (s);
	if (c == 0)
		return ((char *)s_bkp);
	while (s_bkp-- >= s)
		if (*s_bkp == (char)c)
			return ((char *)s_bkp);
	return (NULL);
}
