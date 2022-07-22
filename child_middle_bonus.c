/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_middle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:20:01 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/22 18:31:49 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_middle(int fd[], char *argv, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		msg_perror("Error", EXIT_FAILURE);
	else if (pid == 0)
	{
		if (dup2(fd[1], 1) == -1)
			msg_perror("Error", EXIT_FAILURE);
		close(fd[1]);
		if (dup2(fd[0], 0) == -1)
			msg_perror("Error", EXIT_FAILURE);
		close(fd[0]);
		push_cmd(argv, envp);
	}
}