/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:25:04 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/14 11:17:32 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* HELLO */

int main(int argc, char **argv, char **envp)
{
    char *rl;
//	t_env *env;

	(void)argv;
	if (argc != 1)
	{
		printf("Run minishell using only <./minishell>\n");
		exit (1);
	}
	int i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	char str1[6] = "hello";
	char str2[6] = "world";
	printf("\n%s=\"%s\"\n", str1, str2);
	while (1)
	{ 
    	rl = readline("\x1b[95mMINISHELL\x1b[0m💖$");
		if (!rl)
			return (-1);
//    	printf("%s\n", rl);
		add_history(rl);
		free(rl);
		pwd();
	}
    return (0);
}
