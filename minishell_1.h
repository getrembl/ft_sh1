/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 19:03:48 by getrembl          #+#    #+#             */
/*   Updated: 2015/05/18 16:14:26 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_1_H
# define MINISHELL_1_H

# define BUFFERSIZE	3000

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <signal.h>
# include <errno.h>
# include "get_next_line.h"

/*
** typedef void	(*sighandler_t)(int);
*/

char			**cd_builtin(char **dec, char **envp, char *pwd);
char			**ft_builtin(char **dec, char **envp);
char			**ft_pwd(char **envp);

void			execute(char **dec, char **envp_bkp);
void			prompt(char **envp);

#endif
