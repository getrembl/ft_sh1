/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 18:06:59 by getrembl          #+#    #+#             */
/*   Updated: 2015/04/08 21:46:09 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

static char		**mv_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		tab[i][ft_strlen(tab[i] + 1) + 1] = 0;
		tab[i] = ft_strdup(tab[i + 1]);
		i++;
	}
	return (tab);
}

static int		ft_setenv(char *set, int overwrite, char **envp)
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
			if (ft_strncmp(tab[0], "PATH=", ft_strlen(tab[0])) && tab[1][0] == ':')
			{
				ft_strcat(envp[i], tab[1]);
				return (0);
			}
				else
			{
				ft_strdel(&envp[i]);
				if (!(envp[i] = ft_strdup(tab[0])))
					return (-1);
				ft_strcat(envp[i], tab[1]);
				return (0);
			}
		}
		i++;
	}
	if (!(envp[i] = ft_strdup(tab[0])))
		return (-1);
	ft_strcat(envp[i], tab[1]);
	return (0);
}

static int		ft_unsetenv(char *var, char **envp)
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
	return(0);
}

static void		ft_builtin(char **dec, char **envp)
{
	int			i;

	i = 0;
	if (ft_strncmp(dec[0], "cd", 2) == 0)
		if((i = chdir(dec[1])) == -1)
			exit(EXIT_FAILURE);
	if (ft_strncmp(dec[0], "setenv", 6) == 0)
		if((i = ft_setenv(dec[1], ft_atoi(dec[2]), envp)) == -1
		   || dec[1][ft_strlen(dec[1])] != '=')
			exit(EXIT_FAILURE);
	if (ft_strncmp(dec[0], "unsetenv", 8) == 0)
		if((i = ft_unsetenv(dec[1], envp)) == -1)
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
	exit(EXIT_SUCCESS);
}

void			execute(char *line, char **envp)
{
	char		**dec;
	char		*cmd;
	int			ret;

	dec = ft_strsplit(line, ' ');
	if (ft_strncmp(dec[0], "cd", 2) == 0
		|| ft_strncmp(dec[0], "setenv", 6) == 0
		|| ft_strncmp(dec[0], "unsetenv", 8) == 0
		|| ft_strncmp(line, "env", 3) == 0)
		ft_builtin(dec, envp);
	cmd = ft_strdup("/usr/bin");
	cmd = ft_strcat(cmd, dec[0]);
	dec = mv_tab(dec);
	if ((ret = execve(cmd, dec, envp)) == -1)
		exit(0);
}

//	sur les built-in exit automatiquement
//  retour execve
