/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:44:16 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/22 10:12:47 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_out(int fd[], int fd_out, char *argv, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		msg_perror("Error", EXIT_FAILURE);
	else if (pid == 0)
	{
		if (dup2(fd_out, 1) == -1)
			msg_perror("Error", EXIT_FAILURE);
		close(fd[1]);
		if (dup2(fd[0], 0) == -1)
			msg_perror("Error", EXIT_FAILURE);
		close(fd[0]);
		push_cmd(argv, envp);
	}
}
