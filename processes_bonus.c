/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:08:33 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/25 00:31:26 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_in(int **fd, int file, int argc, char *argv, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		msg_perror("Error", EXIT_FAILURE);
	else if (pid == 0)
	{
		//Fechar os pipes
		if (dup2(file, STDIN_FILENO) == -1)
			msg_perror("Error", EXIT_FAILURE);
		close(file);
		if (dup2(fd[0][1], STDOUT_FILENO) == -1)
			msg_perror("Error", EXIT_FAILURE);
		close(fd[0][1]);
		push_cmd(argv, envp);
	}
}

void	child_middle(int **fd, int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		num_cmd;
	int		index;
	int		index_args;

	index = 0;
	index_args = 0;
	num_cmd = argc-5;
	while (index < num_cmd)
	{
		pid = fork();
		if (pid < 0)
			msg_perror("Error", EXIT_FAILURE);
		else if (pid == 0)
		{
			//Fechar os pipes
			if (dup2(fd[index][0], STDIN_FILENO) == -1)
				msg_perror("Error", EXIT_FAILURE);
			close(fd[index][0]);
			if (dup2(fd[index+1][1], STDOUT_FILENO) == -1)
				msg_perror("Error", EXIT_FAILURE);
			close(fd[index+1][1]);
			push_cmd(argv[index_args+3], envp);
		}
		index++;
		index_args++;
	}
}

void	child_out(int **fd, int file, int argc, char *argv, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		msg_perror("Error", EXIT_FAILURE);
	else if (pid == 0)
	{
		//Fechar os pipes
		if (dup2(file, STDOUT_FILENO) == -1)
			msg_perror("Error", EXIT_FAILURE);
		close(file);
		if (dup2(fd[argc-5][0], STDIN_FILENO) == -1)
			msg_perror("Error", EXIT_FAILURE);
		close(fd[argc-5][0]);
		push_cmd(argv, envp);
	}
}