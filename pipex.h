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


#endif //PIPEX_H
