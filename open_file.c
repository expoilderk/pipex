/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:19:53 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/17 20:24:03 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *path, char *flag)
{
	int		file;
	char	*in;
	char	*out;

	file = 0;
	in = "in";
	out = "out";
	if (flag == in)
	{
		file = open(path, O_RDONLY);
		if (file == -1)
			exit_status("ERROR", EXIT_FAILURE);
	}
	else if (flag == out)
	{
		file = open(path, O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (file == -1)
			exit_status("ERROR", EXIT_FAILURE);
	}
	return (file);
}
