/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:32:17 by getrembl          #+#    #+#             */
/*   Updated: 2015/05/26 12:36:01 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

static void		ft_check(char **envp, char **dec)
{
	pid_t		pid;

	if (ft_strncmp(dec[0], "cd", 2) == 0
		|| ft_strncmp(dec[0], "env", 3) == 0
		|| ft_strncmp(dec[0], "setenv", 6) == 0
		|| ft_strncmp(dec[0], "export", 6) == 0
		|| ft_strncmp(dec[0], "unsetenv", 8) == 0
		|| ft_strncmp(dec[0], "unset", 5) == 0)
	{
		if (!(envp = ft_builtin(dec, envp)))
			ft_putendl_fd("Error. find project's developper and kick him", 2);
	}
	else
	{
		pid = fork();
		if (pid > 0)
			waitpid(pid, 0, 0);
		if (pid == 0)
			execute(dec, envp);
	}
}

static void		ft_sh1(char **envp, char *line)
{
	int			end;
	char		**dec;
	int			i;

	end = 1;
	while (end)
	{
		prompt(envp);
		if ((end = get_next_line(0, &line)) == -1)
			exit(EXIT_FAILURE);
		i = -1;
		while (line[++i])
			if (line[i] == '\t')
				line[i] = ' ';
		line = ft_trim(line, ' ');
		if (ft_strncmp(line, "exit", 5) == 0)
			exit(EXIT_SUCCESS);
		if (line[0])
		{
			dec = ft_strsplit(line, ' ');
			ft_check(envp, dec);
		}
	}
}

int				main(int argc, char *argv[], char *envp[])
{
	char		*line;
	char		**envp_bkp;

	if (!envp || !*envp)
	{
		ft_putendl_fd("Environment is empty. Retry with a good environment", 2);
		return (-1);
	}
	if (!(line = ft_strnew(2)) || !argc || !argv)
		return (-1);
	if (!(envp_bkp = ft_tabdup((const char**)envp)))
	{
		ft_putendl_fd("Envp Error. Find project's developper and kick him", 2);
		return (-1);
	}
	ft_sh1(envp_bkp, line);
	return (0);
}

/*
**
** PSEUDO SHELL
**
** copier environnement
** debut boucle
** ....afficher un prompt
** ....lire la ligne
** ....decouper la ligne
** ....verifier si c'est un builtin ou un executable
** ....si c'est un executable
** ........forker
** ........excecuter la commande
** ........quitter le processus forke
** ....si c'est un builtin
** ........lancer la fonction builtin
** ........retourner l'environnement
** fin boucle
*/
