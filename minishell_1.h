/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 19:03:48 by getrembl          #+#    #+#             */
/*   Updated: 2015/04/04 19:09:48 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINISHELL_1_H
# define	MINISHELL_1_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <signal.h>
# include "get_next_line.h"

typedef void	(*sighandler_t)(int);

void			execute(char *line, char **envp_bkp);
void			prompt(char **envp);

#endif

















