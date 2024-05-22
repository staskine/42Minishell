/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:25:04 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/22 13:26:42 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* HELLO */

int main(int argc, char **argv, char **envp)
{
    char	*rl;
	t_mini	shell;

	(void)argv;
	if (argc != 1)
	{
		printf("Run minishell using only <./minishell>\n");
		exit (1);
	}
	shell.env = add_env(envp);
//	print_export(shell.env);
	while (1)
	{ 
    	rl = readline("\x1b[95mMINISHELL\x1b[0m💖~$ ");
		if (!rl)
			continue ;
 		printf("%s\n", rl);
		add_history(rl);
		free(rl);
	}
    return (0);
}
