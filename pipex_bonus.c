/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:17:19 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/25 18:57:39 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	pipex(int argc, char *argv[], char *envp[])
{
	int		file[2];
	int		index;

	file[IN] = open(argv[1], O_RDONLY, 0666);
	if (file[IN] == -1)
		msg_perror("Error", EXIT_FAILURE);
	file[OUT] = open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file[OUT] == -1)
		msg_perror("Error", EXIT_FAILURE);
	if (dup2(file[IN], STDIN_FILENO) == -1)
		msg_perror("Error", EXIT_FAILURE);
	index = 2;
	while (index < argc-2)
	{
		children(argv[index], envp);
		index++;
	}
	if (dup2(file[OUT], STDOUT_FILENO) == -1)
		msg_perror("Error", EXIT_FAILURE);
	push_cmd(argv[argc-2], envp);
	return (0);
}
