/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:24:00 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/17 21:04:38 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	send_cmd(char *args, char *envp[])
{
	char	**paths;
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(args, ' ');
	paths = get_path(envp);
	if (paths == NULL)
		error_msg("Error: no PATH", 2);
	while (paths[i++])
		exec_cmd(paths, cmd, i);
	ft_free(cmd);
	ft_free(paths);
	exit_status("Error", EXIT_FAILURE);
}
