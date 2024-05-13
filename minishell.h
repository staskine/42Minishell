/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:21:33 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/13 11:48:59 by sataskin         ###   ########.fr       */
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

#endif