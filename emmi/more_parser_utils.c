/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_parser_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:36:05 by emansoor          #+#    #+#             */
/*   Updated: 2024/05/14 13:21:56 by emansoor         ###   ########.fr       */
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

int	find_delimiter(char const *str)
{
	int	index;
	int	delim;

	index = 0;
	delim = 0;
	while (str[index])
	{
		if (str[index] == 32 || str[index] == 9)
		{
			if (str[index] == 32)
				delim = 32;
			else
				delim = 9;
			break ;
		}
		index++;
	}
	return (delim);
}

int	delim_count(char const *str, int delim_type)
{
	int	index;
	int	delim_count;

	index = 0;
	delim_count = 0;
	while (str[index])
	{
		if (str[index] == delim_type)
			delim_count++;
		index++;
	}
	return (delim_count);
}
