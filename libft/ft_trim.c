/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 18:29:08 by getrembl          #+#    #+#             */
/*   Updated: 2015/04/11 18:42:29 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_trim(char *str, char c)
{
	char	*bkp;
	size_t	i;

	i = ft_strlen(str) -1;
	while (str[i] == c)
	{
		str[i] = '\0';
		i--;
	}
	while (*str == c)
		str++;
	bkp = ft_strdup(str);
	return (bkp);
}
