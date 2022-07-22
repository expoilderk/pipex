/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:07:54 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/21 20:45:04 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_error(char *msg, char *cmd, int fd)
{
	ft_putstr_fd(msg, fd);
	ft_putendl_fd(cmd, fd);
	exit(EXIT_FAILURE);
}
