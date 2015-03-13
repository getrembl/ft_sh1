/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:06:32 by getrembl          #+#    #+#             */
/*   Updated: 2014/11/27 16:57:56 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bkp;

	i = 0;
	bkp = b;
	while (i < len)
		bkp[i++] = (unsigned char)c;
	return (b);
}

/*
** Stocker le 'void *' dans un unsigned 'char *', car un 'void *' ne peut etre
** dereference.
** Ne pas oublier de caster mon 'int' en 'unsigned char'
*/
