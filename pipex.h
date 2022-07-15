/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:34:38 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/15 16:50:18 by mreis-me         ###   ########.fr       */
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

void	ft_free(char **matrix);
void	exec_cmd(char *args, char *envp[]);
void	exit_status(char *msg, int status);
int		pipex(int argc, char *argv[], char *envp[]);
void	child_in(int fd[], int fd_in, char *argv, char *envp[]);
void	child_out(int fd[], int fd_out, char *argv, char *envp[]);
int		open_file(char *path, char *flag);
char **get_cmd(char *args);
char **get_path(char *envp[]);






#endif //PIPEX_H
