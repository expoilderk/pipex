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
	
    char *cmd1[] = {"/bin/ls", ".", NULL};
    char *cmd2[] = {"/usr/bin/wc", "-c", NULL};
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
	else /* Pai */
	{
        printf("Pai");
		close(fd1[WRITE_END]); /* Fechar fd desnecessário */

		pipe(fd2); /* Comunica grep e wc */
		pid = fork();

		if(pid == 0) /* Filho 2 */
		{
            printf("Filho 2");
			close(fd2[READ_END]); /* Fechar fd desnecessário */

			dup2(fd1[READ_END], STDIN_FILENO);
			close(fd1[READ_END]);

			dup2(fd2[WRITE_END], STDOUT_FILENO);
			close(fd2[WRITE_END]);

			execve(cmd2[0], cmd2, environ);
		}
	}

	close(fd2[READ_END]); /* Fechar fd que ficou aberto no Pai */

	/* wait para cada filho */
	wait(&status);
	wait(&status);

	return (0);
}