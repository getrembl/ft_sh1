/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:56:58 by getrembl          #+#    #+#             */
/*   Updated: 2015/04/09 20:47:10 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		**ft_strsplit_bis(char const *s, char c, char **tab, size_t *i)
{
	i[0] = 0;
	while (s[i[0]] != '\0')
	{
		while (s[i[0]] == c && s[i[0]])
			i[0]++;
		tab[i[1]] = ft_strnew(ft_wdlen(s, c, i[0]) + 1);
		i[2] = 0;
		while(s[i[0]] != c && s[i[0]])
			tab[i[1]][i[2]++] = s[i[0]++];
		if (i[1] < ft_nwd(s, c))
			i[1]++;
	}
	if (i[1] == 0 && (tab[i[1]][0] != '\0' || s[i[0]] == '\0'))
		i[1]++;
	tab[i[1]] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		i[3];

	i[0] = 0;
	i[1] = 0;
	if (!s || !c || !(tab = (char **)malloc(sizeof(char *) * ft_nwd(s, c) + 1)))
		return (NULL);
	tab[ft_nwd(s, c) + 1] = NULL;
	if (s[i[0]] == '\0')
	{
		tab[i[0]] = NULL;
		return (tab);
	}
	i[0] = 0;
	while (s[i[0]] != c && s[i[0]])
		i[0]++;
	if (!s[i[0]])
	{
		tab[i[1]] = ft_strdup(s);
		tab[i[1] + 1] = NULL;
		return (tab);
	}
	return (ft_strsplit_bis(s, c, tab, i));
}










