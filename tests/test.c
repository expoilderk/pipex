#include "pipex.h"

char	**get_cmd(char *args);

int main(int argc, char const *argv[])
{
    char **matrix;
    //char **cmd = NULL;
    int i;
    (void)argc;

    i = 0;
    matrix = ft_split_mod(argv[1], ' ');
    while(matrix[i])
    {
        printf("%s\n", matrix[i]);
        i++;
    }

    printf("\n\n");

    i = 0;
    while (matrix[i])
	{
		matrix[i] = ft_strtrim(matrix[i], "'\"");
		printf("%s\n", matrix[i]);
		i++;
	}

    return 0;
}