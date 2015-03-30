/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 21:15:32 by getrembl          #+#    #+#             */
/*   Updated: 2015/03/27 19:21:33 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_1_H
# define MINISHELL_1_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <signal.h>
# include "get_next_line.h"

typedef void (*sighandler_t)(int);

char		*prompt(char **envp);

void		execute(char *line, char **envp_bkp);

#endif
