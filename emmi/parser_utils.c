/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:22:26 by emansoor          #+#    #+#             */
/*   Updated: 2024/05/14 13:20:33 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
looks for the first single or double quote in str and returns is, returns
zero if neither quote type is found
*/
static int	quote_identifier(char const *str)
{
	int	index;
	int	quote;

	index = 0;
	quote = 0;
	while (str[index])
	{
		if (str[index] == 39 || str[index] == 34)
		{
			if (str[index] == 39)
				quote = 39;
			else
				quote = 34;
			break ;
		}
		index++;
	}
	return (quote);
}

/*
returns the number of quotes in str, returns -1 for odd number of quotes
*/
static int	quote_count(char const *str, int quote)
{
	int	index;
	int	quotes;

	quotes = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == quote)
			quotes++;
		index++;
	}
	if (quotes % 2 == 0)
		return (quotes);
	return (-1);
}

/*
finds the closing quote in str, returns zero for an error
*/
static int	find_closing_quote(char const *str, t_pars *specs, size_t *index)
{
	(*index)++;
	specs->quotecount--;
	while (str[*index] != specs->quote_type && *index < specs->str_len)
		(*index)++;
	if (specs->quotecount % 2 == 1 && (str[*index + 1] == '\0' || str[*index + 1] == specs->delimiter))
	{
		specs->quotecount--;
		return (1);
	}
	else
		return (0);
}

/*
counts the words in str using space as delimiter, a block of characters
surrounded by single pair of quotes is also treated as a word, returns zero
for an error
*/
int	word_count(char const *str, t_pars *specs)
{
	size_t	index;
	int		substrs;
	int		found_pair;

	index = 0;
	substrs = 0;
	while (index < specs->str_len)
	{
		if (str[index] == specs->quote_type && specs->quotecount % 2 == 0 && specs->quotecount > -1)
		{
			found_pair = find_closing_quote(str, specs, &index);
			if (found_pair > 0)
				substrs++;
			else
				return (0);
		}
		else if ((str[index] != specs->delimiter) && (str[index + 1] == specs->delimiter || str[index + 1] == '\0'))
			substrs++;
		index++;
	}
	return (substrs);
}

/*
initializes a struct with essential parsing info
*/
void	initialize_parsing_specs(t_pars *specs, char const *str)
{
	specs->ptr = NULL;
	specs->quote_type = quote_identifier(str);
	specs->quotecount = quote_count(str, specs->quote_type);
	specs->delimiter = find_delimiter(str);
	specs->delimcount = delim_count(str, specs->delimiter);
	specs->str_len = ft_strlen(str);
	specs->wordcount = 0;
}
