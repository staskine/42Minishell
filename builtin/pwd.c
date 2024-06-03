/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:29:05 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/31 13:56:53 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* moro */
void	pwd(t_env *env)
{
	char *pwd;

	(void)env;
	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
}
