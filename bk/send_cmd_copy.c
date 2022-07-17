/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:24:00 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/17 19:42:47 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	send_cmd(char *args, char *envp[])
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
			if (!paths)
			{
				ft_free(paths);
				error_msg("ERROR: NO PATH", 2);
			}
			while (paths[j++])
				exec_cmd(paths, cmd, j);
		}
		i++;
	}
	ft_free(cmd);
	exit_status("ERROR", EXIT_FAILURE);
}
