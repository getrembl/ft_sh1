/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 22:35:03 by getrembl          #+#    #+#             */
/*   Updated: 2015/02/13 21:07:03 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*s_bkp;
	unsigned int	i[2];

	i[0] = start;
	i[1] = 0;
	if (!s || !(s_bkp = ft_strnew(len + 1)))
		return (NULL);
	if (s && len)
		while (s[i[0]] && i[1] < len)
			s_bkp[i[1]++] = s[i[0]++];
	s_bkp[i[1]] = '\0';
	return (s_bkp);
}
