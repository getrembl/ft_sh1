/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:56:58 by getrembl          #+#    #+#             */
/*   Updated: 2015/05/18 16:11:15 by getrembl         ###   ########.fr       */
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
		tab[i[1]] = ft_strnew(ft_wdlen(s, c, i[0]) + 1);
		i[2] = 0;
		while (s[i[0]] != c && s[i[0]])
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
	char		*b;
	char		**tab;
	size_t		i[3];

	if ((b = ft_strdup(s)))
		b = ft_trim(b, c);
	i[0] = 0;
	if (!b || !c || !(tab = (char **)malloc(sizeof(char *) * ft_nwd(b, c) + 2)))
		return (NULL);
	tab[ft_nwd(b, c)] = NULL;
	i[0] = 0;
	if (*b == '\0')
	{
		tab[i[0]] = NULL;
		return (tab);
	}
	while (b[i[0]] != c && b[i[0]])
		i[0]++;
	if (!b[i[0]])
	{
		tab[0] = ft_strdup(b);
		tab[1] = NULL;
		return (tab);
	}
	return (ft_strsplit_bis(b, c, tab, i));
}
