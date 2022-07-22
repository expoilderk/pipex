/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:17:19 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/22 18:56:18 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	pipex(int argc, char *argv[], char *envp[])
{
	int		fd_1[2];
	int		fd_2[2];
	int		status;
	int		fd_in;
	int		fd_out;

	status = 0;
	if (pipe(fd_1) == -1)
		msg_perror("Error", EXIT_FAILURE);

	if (pipe(fd_2) == -1)
		msg_perror("Error", EXIT_FAILURE);


	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		msg_perror("Error", EXIT_FAILURE);
		
	child_in(fd_1, fd_in, argv[2], envp);
	

	child_middle(fd_2, argv[3], envp);

	
	fd_out = open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_out == -1)
		msg_perror("Error", EXIT_FAILURE);

	child_out(fd_2, fd_out, argv[4], envp);


	close(fd_1[0]);
	close(fd_1[1]);
	close(fd_2[0]);
	close(fd_2[1]);
	
	wait(&status);
	wait(&status);
	wait(&status);
	return (0);
}
