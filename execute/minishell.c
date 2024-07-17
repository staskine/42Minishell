/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:12:23 by emansoor          #+#    #+#             */
/*   Updated: 2024/07/17 08:30:15 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	minishell(t_mini *shell)
{
	t_cmds	*cmd;
	
	open_files(shell, &shell->cmds);
	if (!shell->cmds)
		return ;
	cmd = shell->cmds;
	while (cmd)
	{
		if (cmd->command != NULL)
		{
			nonexistent_cmd(shell);
			dot_cmd(shell);
		}
		cmd = cmd->next;
	}
	run_commands(shell);
}
