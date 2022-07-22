/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:14:47 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/21 21:53:49 by mreis-me         ###   ########.fr       */
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
		cmd[i] = ft_strtrim_mod(cmd[i], "'\"");
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
