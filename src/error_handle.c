#include "../inc/pipex.h"

int	input_errors(int argc, char **argv)
{
	int test_fd;

	test_fd = open(argv[1], O_RDONLY);
	if (argc < 5)
	{
		ft_printf("Error, argumentos no válidos\n\nPor favor siga el formato: <srcfile> <cmd1> <cmd2> <dstfile>\n");
		exit(EXIT_FAILURE);
	}
	if (test_fd == -1)
	{
		close(test_fd);
		return (0);
	}
	return (1);
}
