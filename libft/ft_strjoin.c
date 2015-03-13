/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 10:37:23 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/04 19:23:15 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*strjoin;
	size_t		i;
	size_t		i_bis;

	i = -1;
	if (s1 && s2)
	{
		i_bis = ft_strlen (s1) + ft_strlen (s2) + 1;
		if (!(strjoin = (char *)malloc(sizeof(char) * i_bis)))
			return (NULL);
		while (s1[++i])
			strjoin[i] = s1[i];
		i_bis = 0;
		while (s2[i_bis])
			strjoin[i++] = s2[i_bis++];
		strjoin[i] = '\0';
		return (strjoin);
	}
	return (NULL);
}
