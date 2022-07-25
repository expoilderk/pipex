/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:18:43 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/25 14:32:27 by mreis-me         ###   ########.fr       */
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

#define IN 0
#define OUT 1


void	children(char *argv, char *envp[]);

int		pipex(int argc, char *argv[], char *envp[]);
void	child_in(int fd, int file, char *argv, char *envp[]);
void	child_middle(int **fd, int argc, char *argv[], char *envp[]);
void	child_out(int fd, int file, char *argv, char *envp[]);

void	push_cmd(char *args, char *envp[]);
char	**get_path(char *envp[]);
char	**get_cmd(char *args);
void	exec_cmd(char **paths, char **cmd, int index);

char	**split_cmd(char const *s, char c);
void	mod_countwords(char *str, int words);
void	mod_wordlen(char *str, int slen);
char	*trim_cmd(char const *s1, char const *set);

void	msg_perror(char *msg, int status);
void	msg_error(char *msg, char *cmd, int fd);
void	free_matrix(char **matrix);

#endif //PIPEX_H
