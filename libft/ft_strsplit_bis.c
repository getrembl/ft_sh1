/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 16:59:57 by getrembl          #+#    #+#             */
/*   Updated: 2015/02/09 16:18:54 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit_bis(char const *s, char c, char **tab, size_t i2)
{
	int		i;
	int		i3;

	i = 0;
	i3 = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		tab[i2] = ft_strnew(ft_wdlen(s, c, i) + 1);
		i3 = 0;
		while (s[i] != c && s[i])
			tab[i2][i3++] = s[i++];
		if (i2 < ft_nwd(s, c) - 1)
			i2++;
	}
	if (i2 == 0 && (tab[i2][0] != '\0' || s[i] == '\0'))
		i2++;
	tab[i2] = NULL;
	return (tab);
}
