/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:17:19 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/12 16:12:50 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		main(int argc, char *argv[], char *envp[])
{
	int fd[2];
	int status;
	pid_t pid;
	int fd_in;

	// TODO: Implementar um parser para os args aqui //

	// Abrindo arquivo infile //
	fd_in = open(argv[1], O_RONLY);
	if(fd_in == -1)
		perror("Open Error");

	// função que fazer o pipe //
	if(pipe(fd) == -1)
		perror("Pipe Error");

	pid = fork();
	if(pid < 0)
	{
		perror("Fork Error");
		return (-1);
	}
	else if(pid == 0) // Filho 1
	{
		close(fd[0]); // Fecha o fd de leitura
		dup2(fd[1], 1); // Copia a saída padrão
		close(fd[1]); // Fecha o fd de escrita

		exec_cmd(argv[2]);
		exit(status);
	}
	
	pid = fork();
	if(pid < 0)
	{
		perror("Fork Error");
		return (-1);
	}
	else if(pid == 0) // Filho 2
	{
		close(fd[1]); // Fecha o fd de escrita
		dup2(fd[0], 0); // Copia a entrada padrão
		close(fd[0]); // Fecha o fd de leitura

		exec_cmd(argv[3]);
		exit(status);
	}
	
	close(fd[0]);
	close(fd[1]);
	
	wait(&status);
	wait(&status);

	return (0);
}
