/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:24:36 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/17 17:54:39 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec(char **paths, char **cmd, int index);

void	exec_cmd(char *args, char *envp[])
{
	char	**paths;
	char	**cmd;
	int		j;
	int		i;

	j = 0;
	i = 0;
	cmd = ft_split(args, ' ');
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			paths = ft_split(&envp[i][5], ':');
			while (paths[j++])
				exec(paths, cmd, j);
		}
		i++;
	}
	ft_free(cmd);
	ft_free(paths);
	exit_status("./pipex", EXIT_FAILURE);
}

static void	exec(char **paths, char **cmd, int index)
{
	char	*path;

	path = ft_strjoin(paths[index], "/");
	path = ft_strjoin(path, cmd[0]);
	if (access(path, F_OK | X_OK) == 0)
		if (execve(path, cmd, paths) == -1)
			exit_status("ERROR", EXIT_FAILURE);
	free(path);
}
