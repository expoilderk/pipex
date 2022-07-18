/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:17:19 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/17 21:14:09 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		status;
	int		fd_in;
	int		fd_out;

	status = 0;
	if (argc != 5)
		msg_error("Error: wrong count of arguments", 1);
	if (pipe(fd) == -1)
		msg_perror("Error", EXIT_FAILURE);
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		msg_perror("Error", EXIT_FAILURE);
	child_in(fd, fd_in, argv[2], envp);
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		msg_perror("Error", EXIT_FAILURE);
	child_out(fd, fd_out, argv[3], envp);
	close(fd[0]);
	close(fd[1]);
	wait(&status);
	wait(&status);
	return (0);
}
