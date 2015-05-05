/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:32:17 by getrembl          #+#    #+#             */
/*   Updated: 2015/05/04 10:07:29 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

/*
** int		execve(const char *path, char *const argv[], const *const envp[]);
** pid_t	wait(int *stat_loc);
** pid_t	wait3(int *stat_loc, int options, struct rusage *rusage);
** pid_t	wait4(pid_t pid, int *stat_loc, int options, struct rusage *rusage);
** pid_t	waitpid(pid_t pid, int *stat_loc, int options);
** void		exit(int status);
** pid_t	fork(void);
**	ft_putendl("test");
*/

static char		**env_cpy(char **envp)
{
	char		**ret;
	int			i;

	i = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * ft_tablen(envp) + 1)))
		return (NULL);
	ret[ft_tablen(envp)] = NULL;
	while (envp[i])
	{
		if (!(ret[i] = ft_strdup(envp[i])))
			return (NULL);
		i++;
	}
	return (ret);
}

static void			ft_sh1(char **envp, char *line)
{
	int			end;
	pid_t		pid;

	end = 1;
	while(end)
	{
		prompt(envp);
		if ((end = get_next_line(0, &line)) == -1)
			exit(EXIT_FAILURE);
		line = ft_trim(line, '\t');
		line = ft_trim(line, ' ');
		if (ft_strncmp(line, "exit", 5) == 0)
			exit(EXIT_SUCCESS);
		pid = fork();
		if (pid > 0)
			waitpid(pid, 0, 0);
		if (pid == 0)
			execute(line, envp);
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
	if (!(envp_bkp = env_cpy(envp)))
	{
		ft_putendl_fd("Environment Error. Find project's developper and kick him", 2);
		return (-1);
	}
	ft_sh1(envp_bkp, line);
	return (0);
}

/*
** afficher un prompt
** lire la ligne
** excecuter la commande
** boucler le tout
*/

/*
**	pid_t		father;
**	father = fork();
**	if (father > 0)
**	{
**		put_prompt();
**		wait(NULL);
**	}
**	if (father == 0)
**	{
**		execve("/bin/ls", argv, NULL);
**		fork();
**	}
*/
