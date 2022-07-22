/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:14:47 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/22 10:19:25 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd(char *args)
{
	char	**cmd;
	int		i;

	i = 0;

	cmd = parser_cmd(args, ' ');
	while (cmd[i])
	{
		cmd[i] = trim_cmd(cmd[i], "'\"");
		// TODO: tratamento de erro aqui
		i++;
	}
	if (!cmd)
		free_matrix(cmd);
	return (cmd);
}

/*
- Usar matriz temporária como swap para evitar segmentation fault
- Dar free nas matrizes (proteção para split e trim)
*/
