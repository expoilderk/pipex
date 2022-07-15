/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:31:32 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/15 14:33:53 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_free(char **matrix)
{
	int	index;

	index = -1;
	while (matrix)
		free(matrix[index++]);
	free(matrix);
}
