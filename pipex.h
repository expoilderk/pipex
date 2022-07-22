/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:18:43 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/22 00:07:26 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"

int		pipex(char *argv[], char *envp[]);
void	child_in(int fd[], int fd_in, char *argv, char *envp[]);
void	child_out(int fd[], int fd_out, char *argv, char *envp[]);

char	**get_path(char *envp[]);
char	**get_cmd(char *args);
void	send_cmd(char *args, char *envp[]);
void	exec_cmd(char **paths, char **cmd, int index);

char	**ft_split_mod(char const *s, char c);
void	mod_countwords(char *str, int words);
void	mod_wordlen(char *str, int slen);
char	*ft_strtrim_mod(char const *s1, char const *set);

void	msg_perror(char *msg, int status);
void	msg_error(char *msg, char *cmd, int fd);
void	free_matrix(char **matrix);

#endif //PIPEX_H
