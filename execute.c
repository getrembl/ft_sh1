/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 18:06:59 by getrembl          #+#    #+#             */
/*   Updated: 2015/04/04 20:07:11 by getrembl         ###   ########.fr       */
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

static int		ft_setenv(char *name, char *value, int overwrite)
{

}

static int		ft_unsetenv(char *var)
{

}

static void		ft_builtin(char **dec, char **envp)
{
	int			i;

	i = 0;
	if (dec[0] == "cd")
		if((i = chdir(dec[0])) == -1)
			exit(errno);
	if (dec[0] == "setenv")
		if((i = ft_setenv(dec[1], dec[2], ft_atoi(dec[3]))) == -1
		   || dec[1][ft_strlen(dec[1])] != '=')
			exit(EXIT_FAILURE);
	if (dec[0] == "unsetenv")
		if((i = ft_unsetenv(dec[1])) == -1)
			exit(EXIT_FAILURE);
	if (dec[0] == "env")
	{
		if (envp)
			while (envp[i])
				ft_putstr(envp[i++]);
		else
			ft_putendl("Environment is empty");
	}
	if (dec[0] == "exit")
		exit(0);
	exit(0);
}

void			execute(char *line, char **envp)
{
	char		**dec;
	char		*cmd;
	int			ret;

	if (envp)
	{
		dec = ft_strsplit(line, ' ');
		if (dec[0] == "cd" || dec[0] == "setenv" || dec[0] == "unsetenv"
			|| dec[0] == "env" || dec[0] == "exit")
			ft_builtin(dec, envp);
		cmd = ft_strdup("/usr/bin");
		cmd = ft_strcat(cmd, dec[0]);
		//dec = mv_tab(dec);
		if ((ret = execve(cmd, dec, envp)) == -1)
			exit(0);
	}
}

//	sur les built-in exit automatiquement
//  retour execve

















