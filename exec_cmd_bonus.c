/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:17:15 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/22 18:32:20 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_cmd(char **paths, char **cmd, int index)
{
	char	*path;

	path = ft_strjoin(paths[index], "/");
	path = ft_strjoin(path, cmd[0]);
	if (access(path, F_OK | X_OK) == 0)
		if (execve(path, cmd, paths) == -1)
			msg_perror("Error", EXIT_FAILURE);
	free(path);
}
