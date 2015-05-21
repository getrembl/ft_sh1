/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 11:43:46 by getrembl          #+#    #+#             */
/*   Updated: 2015/05/21 16:33:42 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_1.h"

/*
** setenv segfault, ajouter le PATH avec le $PATH: pour ajouter au PATH.
*/


static char		**ft_setenv(char *set, int overwrite, char **envp)
{
	int			i;
	int			j;
	int			k;
	int			l;

	overwrite = 1;
	i = -1;
	j = ft_wdlen(set, '=', 0);
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], set, j) == 0)
		{
			k = ft_wdlen(envp[i], '=', 0);
			l = ft_strlen(envp[i]);
			while (k <= l)
			{
				envp[i][k] = '\0';
				k++;
			}
			l = 0;
			while (l <= j)
			{
				set++;
				l++;
			}
			envp[i] = ft_strcat(envp[i], set);
		}
	if ((size_t)i == ft_tablen(envp))
		envp[i + 1] = ft_strdup(set);
	return (envp);
/*	int			i;
	char		**tab;

	tab = ft_strsplit(set, '=');
	tab[0] = ft_strncapitalize(tab[0], ft_strlen(tab[0]));
	ft_strcat(tab[0], "=");
	i = 0;
	overwrite = 1;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], tab[0], ft_strlen(tab[0])) == 0)
		{
			if (ft_strncmp(tab[0], "PATH=", 5) == 0
				&& ft_strncmp(tab[1], "$PATH:", 6) == 0)
			{
				while (**tab != ':')
					tab[1]++;
				ft_strcat(envp[i], tab[1]);
				return (envp);
			}
			else
			{
				if (!(envp[i] = ft_strdup(tab[0])))
					return (NULL);
				ft_strcat(envp[i], tab[1]);
				return (envp);
			}
		}
		i++;
	}
	if (!(envp[i] = ft_strdup(tab[0])))
		return (NULL);
	ft_strcat(envp[i], tab[1]);
	return (envp);*/
}

static char		**ft_unsetenv(char *var, char **envp)
{
	int			i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) == 0)
			while (i < (int)ft_tablen(envp))
			{
				if (envp[i + 1])
					envp[i] = ft_strdup(envp[i + 1]);
				else
					envp[i] = NULL;
				i++;
			}
		i++;
	}
	return (envp);
}

static void		ft_putenv(char **envp, char **dec)
{
	int			i[2];

	i[0] = -1;
	i[1] = 0;
	if (envp)
	{
		if (ft_strncmp(dec[0], "env", 3) == 0 && !dec[1])
			while (envp[++i[0]])
				ft_putendl_fd(envp[i[0]], 1);
		else if (ft_strncmp(dec[0], "env", 3) == 0 && dec[1])
		{
			i[0] = -1;
			if (ft_strncmp(dec[1], "-i", 2) == 0)
				while (envp[++i[0]])
					envp[i[0]] = ft_strnew(2);
			else
			{
				while (envp[++i[0]])
					if (ft_strncmp(dec[1], envp[i[0]],\
									ft_wdlen(envp[i[0]], '=', 0) - 1) == 0)
					{
						envp[i[0]] = ft_strchr(envp[i[0]], '=');
						envp[i[0]]++;
						ft_putendl(envp[i[0]]);
						i[1] = 1;
					}
				if (i[1] == 0)
					ft_putendl_fd("Too many arguments for env.", 2);
			}
		}
	}
	else
		ft_putendl("Environment is empty");
}

char			**ft_builtin(char **dec, char **envp)
{
	char		*pwd;

	if (!(pwd = ft_strnew(BUFFERSIZE)))
		return (NULL);
	if (!(pwd = getcwd(pwd, BUFFERSIZE)))
		return (NULL);
	if ((ft_strncmp(dec[0], "cd", 2) == 0))
		if ((envp = cd_builtin(dec, envp, pwd)))
			envp = ft_pwd(envp);
	if ((ft_strncmp(dec[0], "setenv", 6) == 0)
		|| (ft_strncmp(dec[0], "export", 6) == 0))
		if (!(envp = ft_setenv(dec[1], ft_atoi(dec[2]), envp)))
			exit(EXIT_FAILURE);
	if (ft_strncmp(dec[0], "unsetenv", 8) == 0
		|| ft_strncmp(dec[0], "unset", 5) == 0)
		if (!(envp = ft_unsetenv(dec[1], envp)))
			exit(EXIT_FAILURE);
	if (ft_strncmp(dec[0], "env", 3) == 0)
		ft_putenv(envp, dec);
	ft_strdel(&pwd);
	return (envp);
}
