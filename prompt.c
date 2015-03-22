/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 21:14:50 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/22 19:32:35 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

static char	*mkpt(char const *usr,char const *pwd, char *inv)
{
	ft_strcpy(inv, "<");
	ft_strcat(inv, usr);
	ft_strcat(inv, " : ");
	ft_strcat(inv, pwd);
	ft_strcat(inv, ">");
	ft_strcat(inv, "$");
	ft_strcat(inv, " ");
	return (inv);
}

char		*put_prompt(const char *usr_env, const char *pwd_env)
{
	char *inv;
	char const *pwd = position + ft_strlen(position);

	inv = NULL;
	if (usr_env == NULL)
			usr_env = "";
	if (position == NULL)
		position = "";
	while (pwd >= position && *pwd != '/')
		pwd--;
	pwd++;
	if (!(inv = malloc(ft_strlen(usr) + ft_strlen(pwd) + 6)))
		return(NULL);
	if (inv != NULL)
		inv = mkpt(usr, pwd, inv);
	return inv;
}
