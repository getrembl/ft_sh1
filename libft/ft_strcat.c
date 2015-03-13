/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:18:51 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/04 19:22:55 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		i_bis;
	char	*bkp;

	if (!s1 || !s2)
		return (NULL);
	bkp = ft_strnew(ft_strlen(s2) + ft_strlen(s1) + 1);
	i = 0;
	i_bis = 0;
	while (s1[i])
	{
		bkp[i] = s1[i];
		i++;
	}
	while (s2[i_bis] != '\0')
	{
		bkp[i] = s2[i_bis];
		i++;
		i_bis++;
	}
	return (bkp);
}
