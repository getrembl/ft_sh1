/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 21:14:50 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/13 16:22:22 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

static char	*mkpt(char const *usr,char const *rep, char *inv)
{
	ft_strcpy(inv, "<");
	ft_strcat(inv, usr);
	ft_strcat(inv, " : ");
	ft_strcat(inv, rep);
	ft_strcat(inv, ">");
	ft_strcat(inv, "$");
	ft_strcat(inv, " ");
	return (inv);
}

char		*put_prompt(const char *usr_env, const char *pwd_env)
{
	char *inv;
	char const *rep = position + ft_strlen(position);

	inv = NULL;
	if (usr_env == NULL)
			usr_env = "";
	if (position == NULL)
		position = "";
	while (rep >= position && *rep != '/')
		rep--;
	rep++;
	if (!(inv = malloc(ft_strlen(usr) + ft_strlen(rep) + 6)))
		return(NULL);
	if (inv != NULL)
		inv = mkpt(usr, rep, inv);
	return inv;
}
