/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_usr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 15:28:12 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/20 18:12:39 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

char		*env_usr(char const *usr)
{
	char	*bkp;

	bkp = ft_strdup(usr);
	bkp = ft_strchr(bkp, '=');
	bkp++;
	return (bkp);
}

int		main(int argc, char *argv[], char *envp[])
{
	char *qui_suis_je;

	if (!argv[1] && !(argc == 2))
	{
		qui_suis_je = env_usr(envp[8]);
		ft_putstr(qui_suis_je);
	}
	return (0);
}
