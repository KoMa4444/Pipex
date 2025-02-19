#include "../inc/pipex.h"

int input_errors(int argc, char **argv)
{
    if (argc < 5)
    {
        ft_printf("Error, argumentos no válidos\n\nPor favor siga el formato: *srcfile* *cmd1* *cmd2* *dstfile*\n");
        return (0);
    }
    if (open(argv[1], O_RDONLY) == -1)
    {
        perror("Error al abrir el archivo");
        return (0);
    }
    return (1);
}