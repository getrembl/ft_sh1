/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karakhirn <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 20:01:53 by karakhirn         #+#    #+#             */
/*   Updated: 2015/03/20 18:12:47 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

char		*env_pwd(char const *pwd)
{
	char	*bkp;

	bkp = ft_strdup(pwd);
	bkp = ft_strrchr(bkp, '/');
	bkp++;
	return (bkp);
}

int			main(int argc, char *argv[], char *envp[])
{
	char	*ou_suis_je;

	ou_suis_je = env_pwd(envp[16]);
	if (!argv[1] && !(argc == 2))
		ft_putstr(ou_suis_je);
	return (0);
}
