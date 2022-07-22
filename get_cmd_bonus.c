/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:14:47 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/22 18:32:33 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_cmd(char *args)
{
	char	**cmd;
	char	**temp;
	int		index;

	index = 0;
	temp = NULL;
	cmd = parser_cmd(args, ' ');
	while (cmd[index])
		index++;
	temp = (char **)malloc(index * sizeof(char *));
	index = 0;
	while (cmd[index])
	{
		temp[index] = trim_cmd(cmd[index], "'\"");
		free(cmd[index]);
		cmd[index] = temp[index];
		index++;
	}
	return (cmd);
}
