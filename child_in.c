/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:08:33 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/17 21:52:34 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_in(int fd[], int fd_in, char *argv, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		msg_perror("Error", EXIT_FAILURE);
	else if (pid == 0)
	{
		if (dup2(fd_in, 0) == -1)
			msg_perror("Error", EXIT_FAILURE);
		close(fd[0]);
		if (dup2(fd[1], 1) == -1)
			msg_perror("Error", EXIT_FAILURE);
		close(fd[1]);
		send_cmd(argv, envp);
	}
}
