/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 18:06:59 by getrembl          #+#    #+#             */
/*   Updated: 2015/05/18 16:21:10 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

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

void			execute(char **dec, char **envp)
{
	char		*path;
	char		**path_tab;
	int			i;

	i = 0;
	if (!(path = ft_chkpath(envp)))
		exit(EXIT_FAILURE);
	path_tab = ft_strsplit(path, ':');
	while (path_tab[i])
	{
		ft_strcat(path_tab[i], "/");
		if (access(ft_strcat(path_tab[i], dec[0]), X_OK) == 0)
		{
			if ((execve(path_tab[i], dec, envp)) == -1)
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
