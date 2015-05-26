/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 11:38:29 by getrembl          #+#    #+#             */
/*   Updated: 2015/05/26 12:21:07 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_tabdup(const char **tab)
{
	char	**ret;
	int		i;

	i = -1;
	if (!(ret = (char **)malloc(sizeof(char *) * ft_tablen((char**)tab) + 2)))
		return (NULL);
	ret[ft_tablen((char**)tab) + 1] = NULL;
	while (tab[++i])
		if (!(ret[i] = ft_strdup(tab[i])))
			return (NULL);
	ret[i + 1] = NULL;
		return (ret);
}
