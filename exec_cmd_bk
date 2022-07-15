/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:24:36 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/15 14:23:20 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *args, char *envp[])
{
	char **paths;
	char **cmd;
	char *path;
	int j = 0;	
	int i = 0;

	cmd = ft_split(args, ' '); // Criar uma função para fazer o split tratando possíveis erros

	while(envp[i]) // Testar a ideia de eliminar esse while
	{
		if(!ft_strncmp(envp[i], "PATH=", 5))
		{
			paths = ft_split(&envp[i][5], ':');

			while(paths[j])
			{
				path = ft_strjoin(paths[j], "/"); //Talvez fazer uma unica join modificada para colocar o "/"
				path = ft_strjoin(path, cmd[0]); //Aqui entra o comando que vai ser passado como argumento
				
				if(access(path, F_OK | X_OK) == 0) // Criar função que verifica o acesso?
					if(execve(path, cmd, paths) == -1)
						exit_status("ERROR", EXIT_FAILURE);
						
				free(path); // free no path
				j++;
			}
		}
		i++;
	}
	ft_free(cmd); // limpa e libera a matriz
	ft_free(paths); // limpa e libera a matriz
	exit_status("ERROR", EXIT_FAILURE);
}
