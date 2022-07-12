/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:24:36 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/12 10:40:23 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *args)
{
	extern char **environ;

	int i = 0;
	char *env;
	char **paths;
	char *path;
	char **cmd;

	cmd = ft_split(args, ' ');

	while(environ[i])
	{
		if(!ft_strncmp(environ[i], "PATH=", 5))
		{
			paths = ft_split(&environ[i][5], ':');

			int j = 0;
			while(paths[j])
			{
				path = ft_strjoin(paths[j], "/"); //Talvez fazer uma unica join modificada para colocar o "/"
				path = ft_strjoin(path, cmd[0]); //Aqui entra o comando que vai ser passado como argumento
				
				if(!access(path, F_OK | X_OK))
				{
					execve(path, cmd, paths);
				}
				j++;
			}
		}
		i++;
	}
}
