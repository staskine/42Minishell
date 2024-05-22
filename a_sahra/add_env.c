/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:08:56 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/22 11:41:59 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* THIS WILL MAKE A LINKED LIST 
	-with a key and value for the envp 
	-to be added:
		-handling for no value but given
		-handling for no value and not given 
		-pwd="" vs pwd
*/

void	ft_lstadd_back_mini(t_env **lst, t_env *new)
{
	t_env	*node;

	node = *lst;
	if (!new)
		return ;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
}

char	*get_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i] != '=')
		i++;
	key = (char *)malloc(sizeof(char) * (i + 1));
	if (!key)
		exit (1);
	key[i] = '\0';
	i--;
	while (i >= 0)
	{
		key[i] = str[i];
		i--;
	}
	return (key);
}

char	*get_value(char *envp)
{
	int		i;
	int		len;
	char	*value;

	i = 0;
	len = 0;
	while (envp[i] != '=')
		i++;
	len = ft_strlen(envp);
	value = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!value)
		exit (0);
	len = 0;
	i++;
	while (envp[i] != '\0')
	{
		value[len] = envp[i];
		i++;
		len++;
	}
	value[len] = '\0';
	return (value);
}

void	add_input(t_env *node, char *envp)
{
	node->key = get_key(envp);
	node->value = get_value(envp);
}

t_env	*add_env(char **envp)
{
	int		i;
	t_env	*env;
	t_env	*new;
	
	i = 0;
	env = NULL;
	while (envp[i])
	{
		new = malloc(sizeof(t_env));
		if (!new)
		{
			printf("Malloc error");
			exit (1);
		}
		add_input(new, envp[i]);
		new->next = NULL;
		ft_lstadd_back_mini(&env, new);
		i++;
	}
	return (env);
}

