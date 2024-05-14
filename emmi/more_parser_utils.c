/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_parser_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:36:05 by emansoor          #+#    #+#             */
/*   Updated: 2024/05/14 11:38:13 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
return an empty 2D array
*/
char	**null(void)
{
	char	**ptr;

	ptr = (char **)malloc(sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr[0] = NULL;
	return (ptr);
}
