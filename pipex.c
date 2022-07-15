/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:17:19 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/15 11:57:49 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		pipex(int argc, char *argv[], char *envp[])
{
	int fd[2];
	int status;
	int fd_in;
	int fd_out;
	
	status = 0;
	if(argc != 5)
		exit_status("Error: wrong count of arguments", 22); // Fazer tratamento correto perror apenas não funciona

	if(pipe(fd) == -1)
 		exit_status("Pipe", EXIT_FAILURE);

	fd_in = open_file(argv[1], "in");

	child_in(fd, fd_in, argv[2], envp);


	fd_out = open_file(argv[4], "out");

	child_out(fd, fd_out, argv[3], envp);

	close(fd[0]);
	close(fd[1]);
	
	wait(&status);
	wait(&status);

	return (0);
}
