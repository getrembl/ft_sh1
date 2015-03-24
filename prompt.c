/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 21:14:50 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/24 18:25:42 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

static char	*mkpt(char *usr,char *pwd, char *inv)
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

char		*put_prompt(char const *usr, char const *pwd)
{
	char	*ret;
	char	*bkp_usr;
	char	*bkp_pwd;

	if (usr)
	{
		bkp_usr = ft_strdup(usr);
		bkp_usr = ft_strchr(bkp_usr, '=');
		bkp_usr++;
	}
	else
		bkp_usr = "";
	if (pwd)
	{
		bkp_pwd = ft_strdup(pwd);
		bkp_pwd = ft_strrchr(bkp_pwd, '/');
		bkp_pwd++;
	}
	else
		bkp_pwd = "";
	if (!(ret = ft_strnew(ft_strlen(bkp_usr) + ft_strlen(bkp_pwd) + 7)))
		return (NULL);
	ret = mkpt(bkp_usr, bkp_pwd, ret);
	return (ret);
}
