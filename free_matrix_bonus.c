/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:31:32 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/19 16:07:52 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_matrix(char **matrix)
{
	int	index;

	index = -1;
	while (matrix)
		free(matrix[index++]);
	free(matrix);
}
