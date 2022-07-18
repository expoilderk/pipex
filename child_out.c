/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:44:16 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/17 21:03:17 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_out(int fd[], int fd_out, char *argv, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit_status("Error", EXIT_FAILURE);
	else if (pid == 0)
	{
		dup2(fd_out, 1);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		send_cmd(argv, envp);
	}
}
