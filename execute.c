/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 18:06:59 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/31 16:45:31 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

char			**mv_tab(char **tab)
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

void			execute(char *line, char **envp)
{
	char		**dec;
	char		*cmd;

	if (envp)
	{
		dec = ft_strsplit(line, ' ');
		cmd = ft_strdup("/usr/bin");
		cmd = ft_strcat(cmd, dec[0]);
//		dec = mv_tab(dec);
		execve(cmd, dec, NULL);
	}
}










