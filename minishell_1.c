/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:32:17 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/20 18:13:20 by getrembl         ###   ########.fr       */
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

envp[8], envp[16]

int			main(int argc, char *argv[], char *envp[])
{
	int		end;
	char	**line;
	char	*envp_bkp[];

	*envp_bkp = ft_strdup(*envp);
	end = 0;
	if(!(*line = ft_strnew(2)))
		return(-1);
	while (!end)
	{
		char *s;

		s = put_prompt(envp[8], envp[16]);
		if (s != NULL)
		{
			printf ("%s", s);
			fflush (stdout);
			free (s), s = NULL;
		}
		get_next_line(0, line);
		end = strcmp(*line, "quit\n") == 0;
	}
	return (0);
}
/*
int				main(int argc, char *argv[])
{
	pid_t		father;
	father = fork();
	if (father > 0)
	{
		put_prompt();
		wait(NULL);
	}
	if (father == 0)
	{
		execve("/bin/ls", argv, NULL);
		fork();
	}
	return (0);
}
*/
