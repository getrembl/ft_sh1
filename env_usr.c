/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_usr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 15:28:12 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/14 20:03:13 by karakhirn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

char		*env_usr(char const *usr)
{
	char	*bkp;

	bkp = usr;
	bkp = ft_strchr(bkp, '=');
	*bkp++;
	return(bkp);
}
