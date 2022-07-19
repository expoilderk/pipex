/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:14:47 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/19 17:16:51 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd(char *args)
{
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split_mod(args, ' ');
	while (cmd[i])
	{
		cmd[i] = ft_strtrim(cmd[i], "'\""); //tratar caso de erro usando free
		i++;
	}
	if (cmd)
		return (cmd);
	return (NULL);
}
