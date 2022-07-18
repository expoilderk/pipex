/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:50:40 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/18 15:55:46 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
		msg_error("Error: wrong count of arguments", 1);
	pipex(argv, envp);
	return (1);
}
