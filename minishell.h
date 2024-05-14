/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:21:33 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/14 11:38:50 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_cmds
{
    char            **command;
    char            *path;
    int                c_pid;
    int                fd_infile;
    int                fd_outfile;
    int                id;
    int                commands;
    int                valid;
    int                exit_status;
    struct s_cmds    *next;
}            t_cmds;

typedef struct s_pars
{
	char			**ptr;
	int				quote_type;
	int				quotecount;
	int				wordcount;
	size_t			str_len;
}			t_pars;

// typedef struct s_env
// {
// 	char	*export;
// 	char	*key;
// 	char	*value;
// 	t_env	*next;
// }	t_env;

// typedef struct s_mini
// {
// 	t_env	*env;		
// }	t_mini;

int	pwd(void);

/* PARSING */
char	**parser(char const *str);
char	**null(void);
void	initialize_parsing_specs(t_pars *specs, char const *str);

#endif