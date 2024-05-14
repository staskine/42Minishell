/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:09:52 by emansoor          #+#    #+#             */
/*   Updated: 2024/05/14 13:26:11 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
frees a 2D array
*/
static void	free_substrs(t_pars *specs, int nbr_of_subs)
{
	while (nbr_of_subs >= 0)
	{
		free(specs->ptr[nbr_of_subs]);
		nbr_of_subs--;
	}
	free(specs->ptr);
}

/*
finds the closing quote in str, extracts the string and adds it to the 2D ptr
*/
static int	parse_quotes(t_pars *specs, char const *str, int sub_index,
size_t *index)
{
	int		start_index;

	(*index)++;
	start_index = *index;
	while (str[*index] != specs->quote_type && *index < specs->str_len)
		(*index)++;
	specs->ptr[sub_index] = ft_substr(str, start_index, *index - start_index);
	if (!specs->ptr[sub_index])
	{
		free_substrs(specs, sub_index);
		return (1);
	}
	return (0);
}

/*
extracts the next word in str and adds it to ptr
*/
static int	parse_word(t_pars *specs, char const *str, int sub_index,
size_t *index)
{
	int		start_index;

	start_index = *index;
	while (str[*index] != 32 && *index < specs->str_len)
		(*index)++;
	specs->ptr[sub_index] = ft_substr(str, start_index, *index - start_index);
	if (!specs->ptr[sub_index])
	{
		free_substrs(specs, sub_index);
		return (1);
	}
	return (0);
}

/*
looks for words and blocks of quotes to parse until wordcount is met,
returns a pointer to parsed strings
*/
static char	**split_str(t_pars *specs, char const *str)
{
	size_t	index;
	int		sub_index;

	index = 0;
	sub_index = 0;
	while (sub_index < specs->wordcount)
	{
		if (str[index] == specs->quote_type && index < specs->str_len)
		{
			if (parse_quotes(specs, str, sub_index, &index) > 0)
				return (null());
			sub_index++;
		}
		else if (str[index] != 32 && index < specs->str_len)
		{
			if (parse_word(specs, str, sub_index, &index) > 0)
				return (null());
			sub_index++;
		}
		index++;
	}
	specs->ptr[sub_index] = 0;
	return (specs->ptr);
}

/*
returns a double pointer to a parsed string str
*/
char	**parser(char const *str)
{
	t_pars	specs;

	if (ft_strlen(str) == 0)
		return (null());
	initialize_parsing_specs(&specs, str);
	specs.wordcount = word_count(str, &specs);
	if (specs.wordcount)
	{
		specs.ptr = (char **)malloc(sizeof(char *) * (specs.wordcount + 1));
		if (!specs.ptr)
		{
			perror("pipex");
			return (null());
		}
		return (split_str(&specs, str));
	}
	return (null());
}

/*
cc test.c more_parser_utils.c parser.c parser_utils.c ../libft/ft_strlen.c ../libft/ft_strdup.c ../libft/ft_substr.c ../libft/ft_bzero.c ../libft/ft_memset.c -g -fsanitize=address

*/
