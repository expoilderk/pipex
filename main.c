/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:17:19 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/17 20:30:34 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		status;
	pid_t	pid;
	int		fd_in;
	int		fd_out;

	status = 0;
	if (argc != 5)
		error_msg("Error: wrong count of arguments", 1);

	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_in == -1)
		exit_status("Read File", EXIT_FAILURE);
	if (pipe(fd) == -1)
		exit_status("Pipe", EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		exit_status("Fork", EXIT_FAILURE);
	else if (pid == 0)
	{
		dup2(fd_in, 0);
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		send_cmd(argv[2], envp);
	}
	if (fd_out == -1)
		exit_status("Write File", EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		exit_status("Fork", EXIT_FAILURE);
	else if (pid == 0)
	{
		dup2(fd_out, 1);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		send_cmd(argv[3], envp);
		exit(status);
	}
	close(fd[0]);
	close(fd[1]);
	wait(&status);
	wait(&status);
	return (0);
}
