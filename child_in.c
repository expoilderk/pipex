/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:08:33 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/15 11:50:10 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" 

void	child_in(int fd[], int fd_in, char *argv, char *envp[])
{
	pid_t pid;

	pid = fork();
	if(pid < 0)
		exit_status("Fork", EXIT_FAILURE);
	else if(pid == 0) // Filho 1
	{
		dup2(fd_in, 0);
		close(fd[0]); // Fecha o fd de leitura
		
		dup2(fd[1], 1); // Copia a saída padrão
		close(fd[1]); // Fecha o fd de escrita

		exec_cmd(argv, envp);
	}
}
