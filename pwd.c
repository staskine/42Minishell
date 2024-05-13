/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:29:05 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/13 11:36:14 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(void)
{
	char *pwd;
	
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (-1);
	printf("%s\n", pwd);
	return (0);
}
