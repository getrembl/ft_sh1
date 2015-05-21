/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncapitalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 09:43:22 by getrembl          #+#    #+#             */
/*   Updated: 2015/05/19 09:50:21 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncapitalize(char *str, size_t n)
{
	size_t		i;

	i = 0;
	if (str)
		while (str[i] && i <= n)
		{
			if (str[i] >= 97 && str[i] <= 122)
				str[i] -= 32;
			i++;
		}
	return (str);
}
