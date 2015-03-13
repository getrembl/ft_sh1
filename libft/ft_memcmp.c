/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:12:59 by getrembl          #+#    #+#             */
/*   Updated: 2014/11/24 10:37:41 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_bkp;
	const unsigned char	*s2_bkp;

	s1_bkp = s1;
	s2_bkp = s2;
	while (n-- && s1 && s2)
	{
		if (*s1_bkp != *s2_bkp)
			return ((int)*s1_bkp - (int)*s2_bkp);
		s1_bkp++;
		s2_bkp++;
	}
	return (0);
}
