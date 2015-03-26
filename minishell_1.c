/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:32:17 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/26 19:24:36 by getrembl         ###   ########.fr       */
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
*/

static char		**env_cpy(char **envp)
{
	char		**ret;
	int			i;

	i = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * ft_tablen(envp) + 1)))
		return (NULL);
	ret[ft_tablen(envp) + 1] = NULL;
	while (envp[i])
	{
		if (!(ret[i] = ft_strdup(envp[i])))
			return (NULL);
		i++;
	}
	return (ret);
}

int				main(int argc, char *argv[], char *envp[])
{
	int			end;
	char		*line;
	char		*s;
	char		**envp_bkp;
	char		**cmd;

	end = 1;
	if (!(envp_bkp = env_cpy(envp)))
		return (-1);
	if (!(line = ft_strnew(2)))
		return (-1);
	if (argc && argv)
	{
		while (end)
		{
			if (!(s = prompt(envp_bkp)))
				s = "$>";
			ft_putstr(s);
			ft_strdel(&s);
			end = get_next_line(0, &line);
			cmd = ft_strsplit(line, ' ');
			execve("/usr/bin", cmd, envp_bkp);
		}
	}
	return (0);
}

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
