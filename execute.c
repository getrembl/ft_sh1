/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 18:06:59 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/30 16:26:19 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

char			**mv_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		tab[i] = ft_strdup(tab[i + 1]);
		i++;
	}
	return (tab);
}

void			execute(char *line, char **envp)
{
	char		**dec;
	char		*cmd;

	dec = ft_strsplit(line, ' ');
	cmd = ft_strdup("/usr/bin");
	cmd = ft_strcat(cmd, dec[0]);
	dec = mv_tab(dec);
	execve(cmd, dec, envp);
}










