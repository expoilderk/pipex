/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:51:07 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/22 00:08:57 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	mod_wordlen(char *str, int slen)
{
	if (*str == '\"')
	{
		str++;
		slen++;
		while (*str != '\"')
		{
			str++;
			slen++;
		}
	}
	else if (*str == '\'')
	{
		str++;
		slen++;
		while (*str != '\'')
		{
			str++;
			slen++;
		}
	}
}

void	mod_countwords(char *str, int words)
{
	if (*str == '\"')
	{
		str++;
		words++;
		while (*str != '\"')
			str++;
	}
	else if (*str == '\'')
	{
		str++;
		words++;
		while (*str != '\'')
			str++;
	}
}
