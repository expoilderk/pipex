/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:14:53 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/15 16:51:44 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **get_path(char *envp[])
{
	char **paths;
	int i;

	i = 0;
	while(envp[i])
	{
		if(!ft_strncmp(envp[i], "PATH=", 5))
		{
			paths = ft_split(&envp[i][5], ':');
			return (paths);
		}
	}
	return (NULL);
}
