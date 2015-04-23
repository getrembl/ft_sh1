/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 18:06:59 by getrembl          #+#    #+#             */
/*   Updated: 2015/04/21 22:39:37 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

/*
** ft_putendl(test);
*/

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
	while (envp[i] != NULL)
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

static int		ft_cd(char **dec, char *pwd, int i, char **envp)
{
	if (!dec[1])
		dec[1] = ft_strdup("");
	if (dec[1][0] == '/')
		pwd = ft_strdup(dec[1]);
	else
	{
		ft_strcat(pwd, "/");
		ft_strcat(pwd, dec[1]);
	}
	if (access(pwd, F_OK) == 0)
	{
		if (access(pwd, R_OK) == 0)
		{
			ft_putstr(pwd);
			if(chdir(pwd) == -1)
				return (-1);
		}
		else
		{
			ft_putendl_fd("You don't have a rights.", 2);
			return (-1);
		}
	}
	else
	{
		ft_putendl_fd("This directory dosn't exist.", 2);
		return (-1);
	}
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PWD", 3) == 0)
		{
			envp[i] = ft_strdup(pwd);
			return (0);
		}
		i++;
	}
	return (0);
}

static void		ft_builtin(char **dec, char **envp)
{
	int			i;
	size_t		l;
	char		*pwd;

	i = 1;
	l = 5000;
	while (i != 0)
	{
		pwd = ft_strnew(l);
		if ((pwd = getcwd(pwd,l)) != NULL)
			i = 0;
		else
			l *= 2;
	}
	if ((ft_strncmp(dec[0], "cd", 2) == 0))
		if((ft_cd(dec, pwd, i, envp)) == -1)
			exit(EXIT_FAILURE);
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
		{
			ft_putchar('\n');
			while (envp[i])
				ft_putendl(envp[i++]);
		}
		else
			ft_putendl("Environment is empty");
	}
	ft_strdel(&pwd);
}

char			*ft_chkpath(char **envp)
{
	int			i;
	char		*ret;

	i = 0;
	ret = ft_strnew(2);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			ret = ft_strdup(envp[i]);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

void			execute(char *line, char **envp)
{
	char		**dec;
	char		*path;
	char		**path_tab;
	int			i;

	i = 0;
	if (!(path = ft_chkpath(envp)))
		exit(EXIT_FAILURE);
	dec = ft_strsplit(line, ' ');
	if (ft_strncmp(dec[0], "cd", 2) == 0
		|| ft_strncmp(dec[0], "setenv", 6) == 0
		|| ft_strncmp(dec[0], "export", 6) == 0
		|| ft_strncmp(dec[0], "unsetenv", 8) == 0
		|| ft_strncmp(line, "env", 3) == 0)
		ft_builtin(dec, envp);
	else
	{
		path_tab = ft_strsplit(path, ':');
		while (path_tab[i])
		{
			ft_strcat(path_tab[i], "/");
			if (access(ft_strcat(path_tab[i], dec[0]), X_OK) == 0)
			{
				if((execve(path_tab[i], dec, envp)) == -1)
					exit(EXIT_FAILURE);
				else
					exit(EXIT_SUCCESS);
			}
			i++;
		}
		if ((size_t)i == ft_tablen(path_tab))
		{
			ft_putendl_fd("Command not found. Retry dummy...", 2);
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}

//	sur les built-in exit automatiquement
//  retour execve



// utiliser acces pour checker si la commande existe ou non
