/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:08:02 by getrembl          #+#    #+#             */
/*   Updated: 2015/04/11 22:36:25 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nwd(char const *s, char c)
{
	size_t	i;
	int		i_bis;

	i = 1;
	i_bis = 0;
	if (s)
		while (s[i_bis])
		{
			if (s[i_bis] == c && (s[i_bis + 1] != c || !s[i_bis + 1]))
				i++;
			i_bis++;
		}
	return (i);
}
















