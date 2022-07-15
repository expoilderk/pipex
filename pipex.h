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
int	open_file(char *path, char *flag);

#endif //PIPEX_H
