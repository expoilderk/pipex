/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:08:33 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/25 20:39:51 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	children(char *argv, char *envp[])
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		msg_perror("Error", EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		msg_perror("Error", EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[IN]);
		if (dup2(fd[OUT], STDOUT_FILENO) == -1)
			msg_perror("Error", EXIT_FAILURE);
		push_cmd(argv, envp);
	}
	else
	{
		close(fd[OUT]);
		if (dup2(fd[IN], STDIN_FILENO) == -1)
			msg_perror("Error", EXIT_FAILURE);
		wait(0);
	}
}
