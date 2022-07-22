/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:24:00 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/21 22:20:16 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	send_cmd(char *args, char *envp[])
{
	char	**paths;
	char	**cmd;
	int		index;

	index = 0;
	if (access(args, F_OK | X_OK) == 0)
	{
		cmd = get_cmd(args);
		if (execve(cmd[0], cmd, envp) == -1)
			msg_perror("Error", EXIT_FAILURE);
	}
	cmd = get_cmd(args);
	if (access(cmd[0], F_OK | X_OK) == 0)
	{
		if (execve(cmd[0], cmd, envp) == -1)
			msg_perror("Error", EXIT_FAILURE);
	}
	paths = get_path(envp);
	while (paths[index])
	{
		exec_cmd(paths, cmd, index);
		index++;
	}
	msg_error("command not found: ", cmd[0], 2);
}
