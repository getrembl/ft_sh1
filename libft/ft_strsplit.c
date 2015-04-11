/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:56:58 by getrembl          #+#    #+#             */
/*   Updated: 2015/04/11 22:36:49 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		**ft_strsplit_bis(char *s, char c, char **tab, size_t *i)
{
	i[0] = 0;
	i[1] = 0;
	while (s[i[0]])
	{
		while (s[i[0]] == c && s[i[0]])
			i[0]++;
		tab[i[1]] = ft_strnew(ft_wdlen(s, c, i[0]));
		i[2] = 0;
		while(s[i[0]] != c && s[i[0]])
			tab[i[1]][i[2]++] = s[i[0]++];
		if (i[1] < (ft_tablen(tab)))
			i[1]++;
	}
	if (i[1] == 0 && (tab[i[1]][0] != '\0' || s[i[0]] == '\0'))
		i[1]++;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		*bkp;
	char		**tab;
	size_t		i[3];

	if ((bkp = ft_strdup(s)))
		bkp = ft_trim(bkp, c);
	i[0] = 0;
	if (!bkp || !c || !(tab = (char **)malloc(sizeof(char *) * ft_nwd(bkp, c) + 1)))
		return (NULL);
	tab[ft_nwd(bkp, c)] = NULL;
	i[0] = 0;
	if (*bkp == '\0')
	{
		tab[i[0]] = NULL;
		return (tab);
	}
	while (bkp[i[0]] != c && bkp[i[0]])
		i[0]++;
	if (!bkp[i[0]])
	{
		tab[0] = ft_strdup(bkp);
		tab[1] = NULL;
		return (tab);
	}
	return (ft_strsplit_bis(bkp, c, tab, i));
}



