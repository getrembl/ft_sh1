/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 15:13:13 by getrembl          #+#    #+#             */
/*   Updated: 2014/11/27 17:27:49 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*s_bkp;
	size_t	i;

	i = 0;
	if (s && f)
	{
		if (!(s_bkp = (char *)malloc(sizeof(char) * i)))
			return (NULL);
		while (s[i])
		{
			s_bkp[i] = f(s[i]);
			i++;
		}
		return (s_bkp);
	}
	else
		return (NULL);
}
