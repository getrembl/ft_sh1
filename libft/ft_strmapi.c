/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:32:38 by getrembl          #+#    #+#             */
/*   Updated: 2014/11/27 17:34:55 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_bkp;
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		if (!(s_bkp = (char *)malloc(sizeof(char) * i)))
			return (NULL);
		while (s[i])
		{
			s_bkp[i] = (*f)(i, s[i]);
			i++;
		}
		return (s_bkp);
	}
	else
		return (NULL);
}
