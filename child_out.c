/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:44:16 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/15 11:52:36 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" 

void	child_out(int fd[], int fd_out, char *argv, char *envp[])
{
	pid_t pid;

	pid = fork();
	if(pid < 0)
		exit_status("Fork", EXIT_FAILURE);
	else if(pid == 0) // Filho 2
	{
		dup2(fd_out, 1);
		close(fd[1]); // Fecha o fd de escrita
	
		dup2(fd[0], 0); // Copia a entrada padrão
		close(fd[0]); // Fecha o fd de leitura

		exec_cmd(argv, envp);
	//	exit(status); Verificar se realmente é necessário estar aqui
	}
}
