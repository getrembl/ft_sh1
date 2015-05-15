/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 11:43:46 by getrembl          #+#    #+#             */
/*   Updated: 2015/05/15 16:23:52 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// ajouter le 'cd -' vers oldpwd


#include "minishell_1.h"

static char		**ft_setenv(char *set, int overwrite, char **envp)
{
	int			i;
	char		**tab;

	tab = ft_strsplit(set, '=');
	ft_strcat(tab[0], "=");
	i = 0;
	overwrite = 1;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], tab[0], ft_strlen(tab[0])) == 0)
		{
			if (ft_strncmp(tab[0], "PATH=", 5)
				&& ft_strncmp(tab[1], "$PATH:", 6) == 0)
			{
				while (**tab != ':')
					tab[1]++;
				ft_strcat(envp[i], tab[1]);
				return (envp);
			}
			else
			{
				if (!(envp[i] = ft_strdup(tab[0])))
					return (NULL);
				ft_strcat(envp[i], tab[1]);
				return (envp);
			}
		}
		i++;
	}
	if (!(envp[i] = ft_strdup(tab[0])))
		return (NULL);
	ft_strcat(envp[i], tab[1]);
	return (envp);
}

static char		**ft_unsetenv(char *var, char **envp)
{
	int			i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) == 0)
			while (envp[i])
			{
				envp[i] = envp [i + 1];
				i++;
			}
		i++;
	}
	envp[i - 1] = ft_strnew(ft_strlen(envp[i - 1]));
	ft_strdel(&envp[i - 1]);
	envp[i] = NULL;
	return(envp);
}

static void		ft_cd(char *pth, char *cwd)
{
	char		path[BUFFERSIZE];

	ft_strcpy(path, pth);
	if(pth[0] != '/')
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
		{
			if (access(pth, R_OK) == 0)
				chdir(pth);
				else
					ft_putendl_fd("You don't have a rights.", 2);
		}
		else
			ft_putendl_fd("This directory dosn't exist.", 2);
	}
}
static char		**cd_builtin(char **dec, char **envp, int i, char *pwd)
{
	char		*oldpwd;

	oldpwd = ft_strdup(pwd);
	i = -1;
	if (dec[1][0] == '-')
		while (envp[++i])
		{
			if (envp[i] = ft_strncmp(envp[i], "OLDPWD=", 7))
			{

			}
		}
	if ((!dec[1] || !dec[1][0]) ^ (ft_strncmp(dec[1], "~", 1) == 0))
	{
		while (envp[++i])
		{
			if (ft_strncmp(envp[i], "HOME=", 5) == 0)
			{
				dec[1] = ft_strdup(envp[i]);
				dec[1] = ft_strchr(dec[1], '=');
				dec[1]++;
			}
		}
	}
	i = 0;
/*	while (envp[i])
	{
		if (strncmp(envp[i], "OLDPWD=", 7) == 0)
		{
			ft_putendl("test");
			envp = ft_setenv(ft_strcat("OLDPWD=", pwd), 1, envp);
		}
		i++;
	}
*/	ft_cd(dec[1], pwd);
/*	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], "PWD=", 4) == 0)
		{
			pwd = getcwd(envp[i], BUFFERSIZE);
			envp = ft_setenv(ft_strcat("PWD=", pwd), 1, envp);
		}
		i++;
	}
*/	return (envp);
}

char			**ft_builtin(char **dec, char **envp)
{
	int			i;
	size_t		l;
	char		*pwd;

	i = 1;
	l = BUFFERSIZE;
	if	(!(pwd = ft_strnew(l)))
		 return (NULL);
	if (!(pwd = getcwd(pwd, l)))
		return (NULL);
	if ((ft_strncmp(dec[0], "cd", 2) == 0))
		envp = cd_builtin(dec, envp, i, pwd);
	if ((ft_strncmp(dec[0], "setenv", 6) == 0)
		|| (ft_strncmp(dec[0], "export", 6) == 0))
		if(!(envp = ft_setenv(dec[1], ft_atoi(dec[2]), envp)))
			exit(EXIT_FAILURE);
	if (ft_strncmp(dec[0], "unsetenv", 8) == 0)
		if(!(envp = ft_unsetenv(dec[1], envp)))
			exit(EXIT_FAILURE);
	if (ft_strncmp(dec[0], "env", 3) == 0)
	{
		if (envp)
			while (envp[i])
				ft_putendl_fd(envp[i++], 1);
		else
			ft_putendl("Environment is empty");
	}
//	ft_strdel(&pwd);
	return (envp);
}
