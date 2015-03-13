/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:38:41 by getrembl          #+#    #+#             */
/*   Updated: 2015/02/26 17:27:46 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	char	*dst;
	int		size_of_s1;

	size_of_s1 = ft_strlen(s1);
	if (!(dst = (char *)malloc(sizeof(char) * size_of_s1 + 1)))
		return (NULL);
	ft_strcpy (dst, s1);
	return (dst);
}
