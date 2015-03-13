/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 11:48:13 by getrembl          #+#    #+#             */
/*   Updated: 2014/11/27 17:33:06 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strtrim(char const *s)
{
	char		*strtrim;
	size_t		i;
	size_t		i_bis;
	size_t		i_ter;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return ((char *)s);
	i = 0;
	i_bis = ft_strlen (s) - 1;
	i_ter = 0;
	if (!(strtrim = (char *)malloc(sizeof(char) * i_bis)))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		while (i <= i_bis)
		{
			while (s[i_bis] == ' ' || s[i_bis] == '\t' || s[i_bis] == '\n')
				i_bis--;
			strtrim[i_ter++] = s[i++];
		}
	strtrim[i_ter] = '\0';
	return (strtrim);
}
