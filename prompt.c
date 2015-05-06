/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 21:14:50 by getrembl          #+#    #+#             */
/*   Updated: 2015/05/06 17:58:19 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

static char	*mkpt(char *usr, char *pwd, char *inv)
{
	ft_strcpy(inv, "<");
	ft_strcat(inv, usr);
	ft_strcat(inv, " @ ");
	ft_strcat(inv, pwd);
	ft_strcat(inv, ">");
	ft_strcat(inv, ":");
	ft_strcat(inv, "  ");
	return (inv);
}

static char	*mk_usr(char *usr)
{
	if (usr)
	{
		if(!(usr = ft_strdup(usr)))
			return (NULL);
		usr = ft_strchr(usr, '=');
		usr++;
	}
	else
		usr = "";
	return (usr);
}

static char	*mk_pwd(void)
{
	char	*pwd;

	pwd = ft_strnew(2);
	getcwd(pwd, BUFFERSIZE);
	if (pwd)
	{
		pwd = ft_strrchr(pwd, '/');
		pwd++;
	}
	else
		pwd = "";
	return (pwd);
}

void		prompt(char **envp)
{
	char	*ret;
	char	*usr;
	char	*pwd;
	int		i;

	i = 0;
	usr = ft_strnew(2);;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "USER", 4) == 0)
			usr = ft_strdup(envp[i]);
		i++;
	}
	usr = mk_usr(usr);
	pwd = mk_pwd();
	ret = ft_strnew(ft_strlen(usr) + ft_strlen(pwd) + 7);
	ret = mkpt(usr, pwd, ret);
	ft_putstr(ret);
	ft_strdel(&ret);
}



