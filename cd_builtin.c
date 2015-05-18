/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 11:41:29 by getrembl          #+#    #+#             */
/*   Updated: 2015/05/18 16:20:44 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

static void		ft_cd(char *pth, char *cwd)
{
	char		path[BUFFERSIZE];

	ft_strcpy(path, pth);
	if (pth[0] != '/')
	{
		ft_strcat(cwd, "/");
		ft_strcat(cwd, path);
		if (access(cwd, F_OK) == 0)
			if (access(cwd, R_OK) == 0)
				chdir(cwd);
			else
				ft_putendl_fd("You don't have a rights.", 2);
		else
			ft_putendl_fd("This directory dosn't exist.", 2);
	}
	else
	{
		if (access(pth, F_OK) == 0)
			if (access(pth, R_OK) == 0)
				chdir(pth);
			else
				ft_putendl_fd("You don't have a rights.", 2);
		else
			ft_putendl_fd("This directory dosn't exist.", 2);
	}
}

static char		*cd_home(char *dec, char **envp)
{
	int			i;
	char		*tmp;

	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], "HOME=", 5) == 0)
		{
			tmp = ft_strnew(BUFFERSIZE);
			tmp = ft_strcpy(tmp, envp[i]);
			tmp = ft_strchr(tmp, '=');
			tmp++;
			if (dec[1])
			{
				dec++;
				tmp = ft_strcat(tmp, dec);
			}
			dec = ft_strdup(tmp);
		}
	return (dec);
}

char			**cd_builtin(char **dec, char **envp, char *pwd)
{
	int			i;

	if (!dec[1])
		dec[1] = ft_strnew(2);
	if ((!dec[1][0]) || (ft_strncmp(dec[1], "~", 1) == 0))
		dec[1] = cd_home(dec[1], envp);
	i = -1;
	if (dec[1][0] == '-' && !dec[1][1])
		while (envp[++i])
			if (ft_strncmp(envp[i], "OLDPWD=", 7) == 0)
			{
				dec[1] = ft_strdup(envp[i]);
				dec[1] = ft_strrchr(dec[1], '=');
				dec[1]++;
			}
	ft_cd(dec[1], pwd);
	return (envp);
}
