/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:17:19 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/25 00:35:11 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	pipex(int argc, char *argv[], char *envp[])
{
	int		**fd;
	int		file[2];
	int		index;


	fd = (int**)malloc((argc-3) * (sizeof(int*)));
	
	index = 0;
	while (index < argc-3)
	{
		fd[index] = (int*)malloc(2 * sizeof(int*));
	}
		
	index = 0;
	while (index < argc-3)
	{
		if (pipe(fd[index]) == -1)
			msg_perror("Error", EXIT_FAILURE);
		index++;
	}


	file[IN] = open(argv[1], O_RDONLY);
	if (file[IN] == -1)
		msg_perror("Error", EXIT_FAILURE);
	

	child_in(fd, file[IN], argc, argv[2], envp); //função com mais de 4 parametros


	child_middle(fd, argc, argv, envp);


	file[OUT] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file[OUT] == -1)
		msg_perror("Error", EXIT_FAILURE);

	child_out(fd, file[OUT], argc, argv[argc-2], envp); //função com mais de 4 parametros

	//Fechar os pipes

	close(IN);
	close(OUT);

	wait(0);
	wait(0);

	return (0);
}
