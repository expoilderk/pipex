#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define READ_END 0 /* Index de escrita */
#define WRITE_END 1 /* Index de leitura */

int	main(int argc, char *argv[])
{
	int fd1[2];
	int fd2[2];
	int status;
	int pid;
	
    char *cmd1[] = {"/bin/ls", "ls -l", NULL};
    char *cmd2[] = {"/usr/bin/wc", "-l", NULL};
    extern char **environ;

	pipe(fd1); /* Comunica ls e grep */

	pid = fork();

	if(pid == 0) /* Filho 1 */
	{
        printf("Filho 1");
		close(fd1[READ_END]); /* Fechar fd desnecessário */
        
		dup2(fd1[WRITE_END], STDOUT_FILENO);
		close(fd1[WRITE_END]);

		execve(cmd1[0], cmd1, environ);
	}
	else if(pid > 0) /* Pai */
	{
		close(fd1[WRITE_END]); /* Fechar fd desnecessário */

		dup2(fd1[READ_END], STDIN_FILENO);
		close(fd1[READ_END]);

		execve(cmd2[0], cmd2, environ);
	}
	else
	{
		perror("Error");
	}

	/* wait para cada filho */
	wait(&status);
	wait(&status);

	return (0);
}
