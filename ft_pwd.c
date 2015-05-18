/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 14:25:20 by getrembl          #+#    #+#             */
/*   Updated: 2015/05/18 15:17:26 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

char			**ft_pwd(char **envp)
{
	int			i[2];
	char		*pwd;
	char		*oldpwd;

	pwd = ft_strnew(BUFFERSIZE);
	pwd = getcwd(pwd, BUFFERSIZE);
	i[0] = -1;
	while (envp[++i[0]])
		if (ft_strncmp(envp[i[0]], "PWD=", 4) == 0)
		{
			oldpwd = ft_strdup(envp[i[0]]);
			oldpwd = ft_strrchr(oldpwd, '=');
			oldpwd++;
			i[1] = -1;
			while (envp[++i[1]])
				if (ft_strncmp(envp[i[1]], "OLDPWD=", 7) == 0)
				{
					envp[i[1]] = ft_strnew(ft_strlen(oldpwd) + 15);
					envp[i[1]] = ft_strcpy(envp[i[1]], "OLDPWD=");
					envp[i[1]] = ft_strcat(envp[i[1]], oldpwd);
				}
		}
	i[0] = -1;
	while (envp[++i[0]])
		if (ft_strncmp(envp[i[0]], "PWD=", 4) == 0)
		{
			envp[i[0]] = ft_strnew(BUFFERSIZE);
			envp[i[0]] = ft_strcpy(envp[i[0]], "PWD=");
			envp[i[0]] = ft_strcat(envp[i[0]], pwd);
		}
	return (envp);
}











