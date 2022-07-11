#include "pipex.h"

int exec_cmd()
{
	extern char **environ;

	int i = 0;
	char *env;
	char **paths;
	char *path;
	char *test[] = {"ls", "-l", NULL};

	while(environ[i])
	{
		if(!ft_strncmp(environ[i], "PATH=", 5))
		{
			paths = ft_split(&environ[i][5], ':');

			int j = 0;
//			paths = paths+5;
			while(paths[j])
			{
				//printf("%s\n", paths[j]);
				path = ft_strjoin(paths[j], "/"); //Talvez fazer uma unica join modificada para colocar o "/"
				path = ft_strjoin(path, "ls"); //Aqui entra o comando que vai ser passado como argumento
				//printf("%s\n", path);
				
				if(!access(path, F_OK | X_OK))
				{
					//printf("Executa\n");
					execve(path, test, paths);
				}
				
				j++;
			}
		}
		i++;
	}



	return (0);
}
