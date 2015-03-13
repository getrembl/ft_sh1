/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:56:58 by getrembl          #+#    #+#             */
/*   Updated: 2014/12/09 18:26:21 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (!s || !c || !(tab = (char **)malloc(sizeof(char *) * ft_nwd(s, c) + 1)))
		return (NULL);
	if (s[i] == '\0')
	{
		tab[i] = NULL;
		return (tab);
	}
	while (s[i] != c && s[i])
		i++;
	if (!s[i])
	{
		tab[i2] = ft_strdup(s);
		tab[i2 + 1] = NULL;
		return (tab);
	}
	i = 0;
	return (ft_strsplit_bis(s, c, tab, i2));
}
