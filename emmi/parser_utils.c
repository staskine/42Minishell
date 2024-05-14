/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:22:26 by emansoor          #+#    #+#             */
/*   Updated: 2024/05/14 11:37:04 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
looks for the first single or double quote in str and returns is, returns
zero if neither quote type is found
*/
static int	identifier(char const *str)
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
static int	find_closing_quote(char const *str, int *quotes,
int quote, size_t *index)
{
	size_t	str_len;

	(*index)++;
	(*quotes)--;
	str_len = ft_strlen(str);
	while (str[*index] != quote && *index < str_len)
		(*index)++;
	if (*quotes % 2 == 1 && (str[*index + 1] == '\0' || str[*index + 1] == 32 || str[*index + 1] == 9))
	{
		quotes--;
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
static int	word_count(char const *str, int quotes, int quote)
{
	size_t	index;
	int		substrs;
	int		found_pair;
	size_t	str_len;

	index = 0;
	substrs = 0;
	str_len = ft_strlen(str);
	while (index < str_len)
	{
		if (str[index] == quote && quotes % 2 == 0 && quotes > -1)
		{
			found_pair = find_closing_quote(str, &quotes, quote, &index); // if quotes > 2 && quotes % 2 == 0 -> find the next quote where str[index] == quote && str[index + 1] == tab/space || str[index + 1] == '\0'
			if (found_pair > 0)
				substrs++;
			else
				return (0);
		}
		else if ((str[index] != 32 || str[index] != 9) && (str[index + 1] == 32
				|| str[index + 1] == 9 || str[index + 1] == '\0'))
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
	specs->quote_type = identifier(str);
	specs->quotecount = quote_count(str, specs->quote_type);
	specs->wordcount = word_count(str, specs->quotecount, specs->quote_type);
	specs->str_len = ft_strlen(str);
}
