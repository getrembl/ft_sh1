/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:32:17 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/24 21:55:55 by getrembl         ###   ########.fr       */
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

//envp[8], envp[16]

int			main(int argc, char *argv[], char *envp[])
{
	int		end;
	char	*line;
	char	*s;
	char	**envp_bkp;
	int		i;

	i = 0;
	end = 1;
	if(!(envp_bkp = malloc(sizeof(char *) * 100)))
		return (-1);
	while (envp[i])
	{
		if (!(*envp_bkp = malloc(sizeof(char) * ft_strlen(envp[i]) + 1)))
			return (-1);
		i++;
	}
	if (!(line = ft_strnew(2)))
		return(-1);
	if (argc && argv)
	{
		while (end)
		{
			s = put_prompt(envp[8], envp[16]);
			ft_putstr(s);
			ft_strdel(&s);
			end = get_next_line(0, &line);
		}
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
